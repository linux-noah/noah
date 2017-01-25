/*
 * Copyright (C) 2008-2013 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU Lesser General Public License v.2.1.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#ifndef _LIB_LVM2APP_H
#define _LIB_LVM2APP_H

#include <libdevmapper.h>

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************** WARNING ***********************************
 *
 * NOTE: This API is under development and subject to change at any time.
 *
 * Please send feedback to lvm-devel@redhat.com
 *
 *********************************** WARNING ********************************/

/*************************** Design Overview ********************************/

/**
 * \mainpage LVM library API
 *
 * The API is designed around the following basic LVM objects:
 * 1) Physical Volume (pv_t) 2) Volume Group (vg_t) 3) Logical Volume (lv_t).
 *
 * The library provides functions to list the objects in a system,
 * get and set object properties (such as names, UUIDs, and sizes), as well
 * as create/remove objects and perform more complex operations and
 * transformations. Each object instance is represented by a handle, and
 * handles are passed to and from the functions to perform the operations.
 *
 * A central object in the library is the Volume Group, represented by the
 * VG handle, vg_t. Performing an operation on a PV or LV object first
 * requires obtaining a VG handle. Once the vg_t has been obtained, it can
 * be used to enumerate the pv_t and lv_t objects within that vg_t. Attributes
 * of these objects can then be queried or changed.
 *
 * A volume group handle may be obtained with read or write permission.
 * Any attempt to change a property of a pv_t, vg_t, or lv_t without
 * obtaining write permission on the vg_t will fail with EPERM.
 *
 * An application first opening a VG read-only, then later wanting to change
 * a property of an object must first close the VG and re-open with write
 * permission. Currently liblvm provides no mechanism to determine whether
 * the VG has changed on-disk in between these operations - this is the
 * application's responsiblity. One way the application can ensure the VG
 * has not changed is to save the "vg_seqno" field after opening the VG with
 * READ permission. If the application later needs to modify the VG, it can
 * close the VG and re-open with WRITE permission. It should then check
 * whether the original "vg_seqno" obtained with READ permission matches
 * the new one obtained with WRITE permission.
 */

/**
 * Retrieve the library version.
 *
 * The library version is the same format as the full LVM version.
 * The format is as follows:
 *    LVM_MAJOR.LVM_MINOR.LVM_PATCHLEVEL(LVM_LIBAPI)[-LVM_RELEASE]
 * An application wishing to determine compatibility with a particular version
 * of the library should check at least the LVM_MAJOR, LVM_MINOR, and
 * LVM_LIBAPI numbers.  For example, assume the full LVM version is
 * 2.02.50(1)-1.  The application should verify the "2.02" and the "(1)".
 *
 * \return  A string describing the library version.
 */
const char *lvm_library_get_version(void);

/******************************** structures ********************************/

/**
 * Opaque C pointers - Internal structures may change without notice between
 * releases, whereas this API will be changed much less frequently.  Backwards
 * compatibility will normally be preserved in future releases.  On any occasion
 * when the developers do decide to break backwards compatibility in any
 * significant way, the LVM_LIBAPI number (included in the library's soname)
 * will be incremented.
 */

/**
 * \class lvm_t
 *
 * This is the base handle that is needed to open and create objects such as
 * volume groups and logical volumes.  In addition, this handle provides a
 * context for error handling information, saving any error number (see
 * lvm_errno()) and error message (see lvm_errmsg()) that any function may
 * generate.
 */
typedef struct lvm *lvm_t;

/**
 * \class vg_t
 *
 * The volume group object is a central object in the library, and can be
 * either a read-only object or a read-write object depending on the function
 * used to obtain the object handle. For example, lvm_vg_create() always
 * returns a read/write handle, while lvm_vg_open() has a "mode" argument
 * to define the read/write mode of the handle.
 */
typedef struct volume_group *vg_t;

/**
 * \class lv_t
 *
 * This logical volume object is bound to a vg_t and has the same
 * read/write mode as the vg_t.  Changes will be written to disk
 * when the vg_t gets committed to disk by calling lvm_vg_write().
 */
typedef struct logical_volume *lv_t;

/**
 * \class pv_t
 *
 * This physical volume object is bound to a vg_t and has the same
 * read/write mode as the vg_t.  Changes will be written to disk
 * when the vg_t gets committed to disk by calling lvm_vg_write().
 */
typedef struct physical_volume *pv_t;

/**
 * \class lvseg_t
 *
 * This lv segment object is bound to a lv_t.
 */
typedef struct lv_segment *lvseg_t;

/**
 * \class pvseg_t
 *
 * This pv segment object is bound to a pv_t.
 */
typedef struct pv_segment *pvseg_t;

/**
 * \class lv_create_params
 *
 * This lv_create_params represents the plethora of available options when
 * creating a logical volume
 */
typedef struct lvm_lv_create_params *lv_create_params_t;

/**
 * \class pv_create_params
 *
 * This pv_create_params represents the plethora of available options when
 * creating a physical volume
 */
typedef struct lvm_pv_create_params *pv_create_params_t;

/**
 * Logical Volume object list.
 *
 * Lists of these structures are returned by lvm_vg_list_lvs().
 */
typedef struct lvm_lv_list {
	struct dm_list list;
	lv_t lv;
} lv_list_t;

/**
 * Logical Volume Segment object list.
 *
 * Lists of these structures are returned by lvm_lv_list_lvsegs().
 */
typedef struct lvm_lvseg_list {
	struct dm_list list;
	lvseg_t lvseg;
} lvseg_list_t;

/**
 * Physical volume object list.
 *
 * Lists of these structures are returned by lvm_vg_list_pvs().
 */
typedef struct lvm_pv_list {
	struct dm_list list;
	pv_t pv;
} pv_list_t;

/**
 * Physical Volume Segment object list.
 *
 * Lists of these structures are returned by lvm_pv_list_pvsegs().
 */
typedef struct lvm_pvseg_list {
	struct dm_list list;
	pvseg_t pvseg;
} pvseg_list_t;

/**
 * String list.
 *
 * This string list contains read-only strings.
 * Lists of these structures are returned by functions such as
 * lvm_list_vg_names() and lvm_list_vg_uuids().
 */
typedef struct lvm_str_list {
	struct dm_list list;
	const char *str;
} lvm_str_list_t;

/**
 * Property Value
 *
 * This structure defines a single LVM property value for an LVM object.
 * The structures are returned by functions such as
 * lvm_vg_get_property().
 *
 * is_settable: indicates whether a 'set' function exists for this property
 * is_string: indicates whether this property is a string (1) or not (0)
 * is_integer: indicates whether this property is an integer (1) or not (0)
 * is_valid: indicates whether 'value' is valid (1) or not (0)
 */
typedef struct lvm_property_value {
	uint32_t is_settable:1;
	uint32_t is_string:1;
	uint32_t is_integer:1;
	uint32_t is_valid:1;
	uint32_t is_signed:1;
	uint32_t padding:27;
	union {
		const char *string;
		uint64_t integer;
		int64_t signed_integer;
	} value;
} lvm_property_value_t;

/*************************** generic lvm handling ***************************/
/**
 * Create a LVM handle.
 *
 * \memberof lvm_t
 *
 * Once all LVM operations have been completed, use lvm_quit() to release
 * the handle and any associated resources.
 *
 * \param system_dir
 * Set an alternative LVM system directory. Use NULL to use the
 * default value. If the environment variable LVM_SYSTEM_DIR is set,
 * it will override any system_dir setting.
 *
 * \return
 * A valid LVM handle is returned or NULL if there has been a
 * memory allocation problem. You have to check if an error occured
 * with the lvm_error() function.
 */
lvm_t lvm_init(const char *system_dir);

/**
 * Destroy a LVM handle allocated with lvm_init().
 *
 * \memberof lvm_t
 *
 * This function should be used after all LVM operations are complete or after
 * an unrecoverable error.  Destroying the LVM handle frees the memory and
 * other resources associated with the handle.  Once destroyed, the handle
 * cannot be used subsequently.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 */
void lvm_quit(lvm_t libh);

/**
 * Reload the original configuration from the system directory.
 *
 * \memberof lvm_t
 *
 * This function should be used when any LVM configuration changes in the LVM
 * system_dir or by another lvm_config* function, and the change is needed by
 * the application.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_config_reload(lvm_t libh);

/**
 * Override the LVM configuration with a configuration string.
 *
 * \memberof lvm_t
 *
 * This function is equivalent to the --config option on lvm commands.
 * Once this API has been used to over-ride the configuration,
 * use lvm_config_reload() to apply the new settings.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \param   config_string
 * LVM configuration string to apply.  See the lvm.conf file man page
 * for the format of the config string.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_config_override(lvm_t libh, const char *config_string);

/**
 * Find a boolean value in the LVM configuration.
 *
 * \memberof lvm_t
 *
 * This function finds a boolean value associated with a path
 * in current LVM configuration.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \param   config_path
 * A path in LVM configuration
 *
 * \param   fail
 * Value to return if the path is not found.
 *
 * \return
 * boolean value for 'config_path' (success) or the value of 'fail' (error)
 */
int lvm_config_find_bool(lvm_t libh, const char *config_path, int fail);

/**
 * Return stored error no describing last LVM API error.
 *
 * \memberof lvm_t
 *
 * Users of liblvm should use lvm_errno to determine the details of a any
 * failure of the last call.  A basic success or fail is always returned by
 * every function, either by returning a 0 or -1, or a non-NULL / NULL.
 * If a function has failed, lvm_errno may be used to get a more specific
 * error code describing the failure.  In this way, lvm_errno may be used
 * after every function call, even after a 'get' function call that simply
 * returns a value.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \return
 * An errno value describing the last LVM error.
 */
int lvm_errno(lvm_t libh);

/**
 * Return stored error message describing last LVM error.
 *
 * \memberof lvm_t
 *
 * This function may be used in conjunction with lvm_errno() to obtain more
 * specific error information for a function that is known to have failed.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \return
 * An error string describing the last LVM error.
 */
const char *lvm_errmsg(lvm_t libh);

/**
 * Scan all devices on the system for VGs and LVM metadata.
 *
 * \memberof lvm_t
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_scan(lvm_t libh);

/**
 * Return the list of volume group names.
 *
 * \memberof lvm_t
 *
 * The memory allocated for the list is tied to the lvm_t handle and will be
 * released when lvm_quit() is called.
 *
 * NOTE: This function normally does not scan devices in the system for LVM
 * metadata.  To scan the system, use lvm_scan().
 *
 * To process the list, use the dm_list iterator functions.  For example:
 *      vg_t vg;
 *      struct dm_list *vgnames;
 *      struct lvm_str_list *strl;
 *
 *      vgnames = lvm_list_vg_names(libh);
 *	dm_list_iterate_items(strl, vgnames) {
 *		vgname = strl->str;
 *              vg = lvm_vg_open(libh, vgname, "r");
 *              // do something with vg
 *              lvm_vg_close(vg);
 *      }
 *
 *
 * \return
 * A list with entries of type struct lvm_str_list, containing the
 * VG name strings of the Volume Groups known to the system.
 * NULL is returned if unable to allocate memory.
 * An empty list (verify with dm_list_empty) is returned if no VGs
 * exist on the system.
 */
struct dm_list *lvm_list_vg_names(lvm_t libh);

/**
 * Return the list of volume group uuids.
 *
 * \memberof lvm_t
 *
 * The memory allocated for the list is tied to the lvm_t handle and will be
 * released when lvm_quit() is called.
 *
 * NOTE: This function normally does not scan devices in the system for LVM
 * metadata.  To scan the system, use lvm_scan().
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \return
 * A list with entries of type struct lvm_str_list, containing the
 * VG UUID strings of the Volume Groups known to the system.
 * NULL is returned if unable to allocate memory.
 * An empty list (verify with dm_list_empty) is returned if no VGs
 * exist on the system.
 */
struct dm_list *lvm_list_vg_uuids(lvm_t libh);

/**
 * Return the volume group name given a PV UUID
 *
 * \memberof lvm_t
 *
 * The memory allocated for the name is tied to the lvm_t handle and will be
 * released when lvm_quit() is called.
 *
 * NOTE: This function may scan devices in the system for LVM metadata.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \return
 * The volume group name for the given PV UUID.
 * NULL is returned if the PV UUID is not associated with a volume group.
 */
const char *lvm_vgname_from_pvid(lvm_t libh, const char *pvid);

/**
 * Return the volume group name given a device name
 *
 * \memberof lvm_t
 *
 * The memory allocated for the name is tied to the lvm_t handle and will be
 * released when lvm_quit() is called.
 *
 * NOTE: This function may scan devices in the system for LVM metadata.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \return
 * The volume group name for the given device name.
 * NULL is returned if the device is not an LVM device.
 *
 */
const char *lvm_vgname_from_device(lvm_t libh, const char *device);

/**
 * Open an existing VG.
 *
 * Open a VG for reading or writing.
 *
 * \memberof lvm_t
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \param   vgname
 * Name of the VG to open.
 *
 * \param   mode
 * Open mode - either "r" (read) or "w" (read/write).
 * Any other character results in an error with EINVAL set.
 *
 * \param   flags
 * Open flags - currently ignored.
 *
 * \return  non-NULL VG handle (success) or NULL (failure).
 */
vg_t lvm_vg_open(lvm_t libh, const char *vgname, const char *mode,
		  uint32_t flags);

/**
 * Validate a name to be used for new VG construction.
 *
 * This function checks that the name has no invalid characters,
 * the length doesn't exceed maximum and that the VG name isn't already in use
 * and that the name adheres to any other limitations.
 *
 * \param libh
 * Valid library handle
 *
 * \param name
 * Name to validate for new VG create.
 */
int lvm_vg_name_validate(lvm_t libh, const char *vg_name);

/**
 * Create a VG with default parameters.
 *
 * \memberof lvm_t
 *
 * This function creates a Volume Group object in memory.
 * Upon success, other APIs may be used to set non-default parameters.
 * For example, to set a non-default extent size, use lvm_vg_set_extent_size().
 * Next, to add physical storage devices to the volume group, use
 * lvm_vg_extend() for each device.
 * Once all parameters are set appropriately and all devices are added to the
 * VG, use lvm_vg_write() to commit the new VG to disk, and lvm_vg_close() to
 * release the VG handle.
 *
 * \param   libh
 * Handle obtained from lvm_init().
 *
 * \param   vg_name
 * Name of the VG to open.
 *
 * \return
 * non-NULL vg handle (success) or NULL (failure)
 */
vg_t lvm_vg_create(lvm_t libh, const char *vg_name);

/*************************** volume group handling **************************/

/**
 * Return a list of LV handles for a given VG handle.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * A list of lvm_lv_list structures containing lv handles for this vg.
 * If no LVs exist on the given VG, NULL is returned.
 */
struct dm_list *lvm_vg_list_lvs(vg_t vg);

/**
 * Return a list of PV handles for all.
 *
 * \memberof lvm_t
 *
 * \param   libh
 * Library handle retrieved from lvm_init
 *
 * \return
 * A list of lvm_pv_list structures containing pv handles for all physical
 * volumes. If no PVs exist or a global lock was unable to be obtained a
 * NULL is returned.  Do not attempt to remove one of the PVs until after the
 * call to lvm_list_pvs_free has been made.
 */
struct dm_list *lvm_list_pvs(lvm_t libh);

/**
 * Free the resources used by acquiring the pvlist.  This should be called as
 * soon as possible after processing the needed information from the pv list as
 * a global lock is held.
 *
 * \param	pvlist
 * PV list to be freed
 *
 * \return
 * 0 on success, else -1 with library errno and text set.
 */
int lvm_list_pvs_free(struct dm_list *pvlist);

/**
 *  Create a physical volume.
 *  \param	libh	Library handle
 *  \param	pv_name	The physical volume name
 *  \param	size	Size of physical volume, 0 = use all available.
 *  \return
 *  0 on success, else -1 with library errno and text set.
 */
int lvm_pv_create(lvm_t libh, const char *pv_name, uint64_t size);

/**
 * Create a physical volume parameter object for PV creation.
 *
 * \param	libh	Library handle
 * \param	pv_name	Device name
 *
 * \return
 * NULL on error, else valid parameter object to use.
 */
pv_create_params_t lvm_pv_params_create(lvm_t libh, const char *pv_name);

/**
 * Create a parameter object to use in function lvm_pv_create_adv
 *
 * 	\param 	params	The params object to get property value from
 * 	\param	name	The name of the property to retrieve
 *
 * 	Available properties:
 *
 * 	size					zero indicates use detected size of device
 * 							(recommended and default)
 *	pvmetadatacopies		Number of metadata copies (0,1,2)
 *	pvmetadatasize			The approx. size to be to be set aside for metadata
 *	data_alignment			Align the start of the data to a multiple of
 *							this number
 *	data_alignment_offset	Shift the start of the data area by this addl.
 *							offset
 *	zero					Set to 1 to zero out first 2048 bytes of
 *							device, 0 to not (default is 1)
 *
 * 	\return
 * 	lvm_property_value
 */
struct lvm_property_value lvm_pv_params_get_property(
						const pv_create_params_t params,
						const char *name);

/**
 * Sets a property of a PV parameter create object.
 *
 * \param	params		The parameter object
 * \param	name		The name of the property to set (see get prop list)
 * \param	prop		The property to set the value on.
 */
int lvm_pv_params_set_property(pv_create_params_t params, const char *name,
								struct lvm_property_value *prop);
/**
 * Creates a physical volume using the supplied params object.
 *
 * \param	params		The parameters to use for physical volume creation
 *
 * \return
 * -1 on error, 0 on success.
 */
int lvm_pv_create_adv(pv_create_params_t params);

/**
 *  Remove a physical volume.
 *  Note: You cannot remove a PV while iterating through the list of PVs as
 *  locks are held for the PV list.
 *  \param	libh	Library handle
 *  \param	pv_name	The physical volume name
 *  \return
 *  0 on success, else -1 with library errno and text set.
 */
int lvm_pv_remove(lvm_t libh, const char *pv_name);

/**
 * Return a list of PV handles for a given VG handle.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * A list of lvm_pv_list structures containing pv handles for this vg.
 * If no PVs exist on the given VG, NULL is returned.
 */
struct dm_list *lvm_vg_list_pvs(vg_t vg);

/**
 * Write a VG to disk.
 *
 * \memberof vg_t
 *
 * This function commits the Volume Group object referenced by the VG handle
 * to disk. Upon failure, retry the operation and/or release the VG handle
 * with lvm_vg_close().
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_write(vg_t vg);

/**
 * Remove a VG from the system.
 *
 * \memberof vg_t
 *
 * This function removes a Volume Group object in memory, and requires
 * calling lvm_vg_write() to commit the removal to disk.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_remove(vg_t vg);

/**
 * Close a VG opened with lvm_vg_create or lvm_vg_open().
 *
 * \memberof vg_t
 *
 * This function releases a VG handle and any resources associated with the
 * handle.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_close(vg_t vg);

/**
 * Extend a VG by adding a device.
 *
 * \memberof vg_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully adding a device, use lvm_vg_write() to commit the new VG
 * to disk.  Upon failure, retry the operation or release the VG handle with
 * lvm_vg_close().
 * If the device is not initialized for LVM use, it will be initialized
 * before adding to the VG.  Although some internal checks are done,
 * the caller should be sure the device is not in use by other subsystems
 * before calling lvm_vg_extend().
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   device
 * Absolute pathname of device to add to VG.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_extend(vg_t vg, const char *device);

/**
 * Reduce a VG by removing an unused device.
 *
 * \memberof vg_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully removing a device, use lvm_vg_write() to commit the new VG
 * to disk.  Upon failure, retry the operation or release the VG handle with
 * lvm_vg_close().
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   device
 * Name of device to remove from VG.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_reduce(vg_t vg, const char *device);

/**
 * Add a tag to a VG.
 *
 * \memberof vg_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully adding a tag, use lvm_vg_write() to commit the
 * new VG to disk.  Upon failure, retry the operation or release the VG handle
 * with lvm_vg_close().
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   tag
 * Tag to add to the VG.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_add_tag(vg_t vg, const char *tag);

/**
 * Remove a tag from a VG.
 *
 * \memberof vg_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully removing a tag, use lvm_vg_write() to commit the
 * new VG to disk.  Upon failure, retry the operation or release the VG handle
 * with lvm_vg_close().
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   tag
 * Tag to remove from VG.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_remove_tag(vg_t vg, const char *tag);

/**
 * Set the extent size of a VG.
 *
 * \memberof vg_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully setting a new extent size, use lvm_vg_write() to commit
 * the new VG to disk.  Upon failure, retry the operation or release the VG
 * handle with lvm_vg_close().
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   new_size
 * New extent size in bytes.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_set_extent_size(vg_t vg, uint32_t new_size);

/**
 * Get whether or not a volume group is clustered.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * 1 if the VG is clustered, 0 if not
 */
uint64_t lvm_vg_is_clustered(vg_t vg);

/**
 * Get whether or not a volume group is exported.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * 1 if the VG is exported, 0 if not
 */
uint64_t lvm_vg_is_exported(vg_t vg);

/**
 * Get whether or not a volume group is a partial volume group.
 *
 * \memberof vg_t
 *
 * When one or more physical volumes belonging to the volume group
 * are missing from the system the volume group is a partial volume
 * group.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * 1 if the VG is PVs, 0 if not
 */
uint64_t lvm_vg_is_partial(vg_t vg);

/**
 * Get the current metadata sequence number of a volume group.
 *
 * \memberof vg_t
 *
 * The metadata sequence number is incrented for each metadata change.
 * Applications may use the sequence number to determine if any LVM objects
 * have changed from a prior query.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Metadata sequence number.
 */
uint64_t lvm_vg_get_seqno(const vg_t vg);

/**
 * Get the current uuid of a volume group.
 *
 * \memberof vg_t
 *
 * The memory allocated for the uuid is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Copy of the uuid string.
 */
const char *lvm_vg_get_uuid(const vg_t vg);

/**
 * Get the current name of a volume group.
 *
 * \memberof vg_t
 *
 * The memory allocated for the name is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Copy of the name.
 */
const char *lvm_vg_get_name(const vg_t vg);

/**
 * Get the current size in bytes of a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Size in bytes.
 */
uint64_t lvm_vg_get_size(const vg_t vg);

/**
 * Get the current unallocated space in bytes of a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Free size in bytes.
 */
uint64_t lvm_vg_get_free_size(const vg_t vg);

/**
 * Get the current extent size in bytes of a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Extent size in bytes.
 */
uint64_t lvm_vg_get_extent_size(const vg_t vg);

/**
 * Get the current number of total extents of a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Extent count.
 */
uint64_t lvm_vg_get_extent_count(const vg_t vg);

/**
 * Get the current number of free extents of a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Free extent count.
 */
uint64_t lvm_vg_get_free_extent_count(const vg_t vg);

/**
 * Get the current number of physical volumes of a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Physical volume count.
 */
uint64_t lvm_vg_get_pv_count(const vg_t vg);

/**
 * Get the maximum number of physical volumes allowed in a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Maximum number of physical volumes allowed in a volume group.
 */
uint64_t lvm_vg_get_max_pv(const vg_t vg);

/**
 * Get the maximum number of logical volumes allowed in a volume group.
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \return
 * Maximum number of logical volumes allowed in a volume group.
 */
uint64_t lvm_vg_get_max_lv(const vg_t vg);

/**
 * Return the list of volume group tags.
 *
 * \memberof vg_t
 *
 * The memory allocated for the list is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * To process the list, use the dm_list iterator functions.  For example:
 *      vg_t vg;
 *      struct dm_list *tags;
 *      struct lvm_str_list *strl;
 *
 *      tags = lvm_vg_get_tags(vg);
 *	dm_list_iterate_items(strl, tags) {
 *		tag = strl->str;
 *              // do something with tag
 *      }
 *
 *
 * \return
 * A list with entries of type struct lvm_str_list, containing the
 * tag strings attached to volume group.
 * If no tags are attached to the given VG, an empty list is returned
 * (check with dm_list_empty()).
 * If there is a problem obtaining the list of tags, NULL is returned.
 */
struct dm_list *lvm_vg_get_tags(const vg_t vg);

/**
 * Get the value of a VG property
 *
 * \memberof vg_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   name
 * Name of property to query.  See vgs man page for full list of properties
 * that may be queried.
 *
 * The memory allocated for a string property value is tied to the vg_t
 * handle and will be released when lvm_vg_close() is called.
 *
 * Example:
 *      lvm_property_value v;
 *      char *prop_name = "vg_mda_count";
 *
 *      v = lvm_vg_get_property(vg, prop_name);
 *      if (!v.is_valid) {
 *           printf("Invalid property name or unable to query"
 *                  "'%s', errno = %d.\n", prop_name, lvm_errno(libh));
 *           return;
 *      }
 *      if (v.is_string)
 *           printf(", value = %s\n", v.value.string);
 *	if (v.is_integer)
 *           printf(", value = %"PRIu64"\n", v.value.integer);
 *
 *
 * \return
 * lvm_property_value structure that will contain the current
 * value of the property.  Caller should check 'is_valid' flag before using
 * the value.  If 'is_valid' is not set, caller should check lvm_errno()
 * for specific error.
 */
struct lvm_property_value lvm_vg_get_property(const vg_t vg, const char *name);

/**
 * Set the value of a VG property.  Note that the property must be
 * a 'settable' property, as evidenced by the 'is_settable' flag
 * when querying the property.
 *
 * \memberof vg_t
 *
 * The memory allocated for a string property value is tied to the vg_t
 * handle and will be released when lvm_vg_close() is called.
 *
 * Example (integer):
 *      lvm_property_value copies;
 *
 *      if (lvm_vg_get_property(vg, "vg_mda_copies", &copies) < 0) {
 *              // Error - unable to query property
 *      }
 *      if (!copies.is_settable) {
 *              // Error - property not settable
 *      }
 *      copies.value.integer = 2;
 *      if (lvm_vg_set_property(vg, "vg_mda_copies", &copies) < 0) {
 *              // handle error
 *      }
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_set_property(const vg_t vg, const char *name,
			struct lvm_property_value *value);

/************************** logical volume handling *************************/

/**
 * Create a linear logical volume.
 * This function commits the change to disk and does _not_ require calling
 * lvm_vg_write().
 * NOTE: The commit behavior of this function is subject to change
 * as the API is developed.
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   name
 * Name of logical volume to create.
 *
 * \param   size
 * Size of logical volume in extents.
 *
 * \return
 * non-NULL handle to an LV object created, or NULL if creation fails.
 *
 */
lv_t lvm_vg_create_lv_linear(vg_t vg, const char *name, uint64_t size);

/**
 * Return a list of lvseg handles for a given LV handle.
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * A list of lvm_lvseg_list structures containing lvseg handles for this lv.
 */
struct dm_list *lvm_lv_list_lvsegs(lv_t lv);

/**
 * Lookup an LV handle in a VG by the LV name.
 *
 * \memberof lv_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   name
 * Name of LV to lookup.
 *
 * \return
 * non-NULL handle to the LV 'name' attached to the VG.
 * NULL is returned if the LV name is not associated with the VG handle.
 */
lv_t lvm_lv_from_name(vg_t vg, const char *name);

/**
 * Lookup an LV handle in a VG by the LV uuid.
 * The form of the uuid may be either the formatted, human-readable form,
 * or the non-formatted form.
 *
 * \memberof lv_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   uuid
 * UUID of LV to lookup.
 *
 * \return
 * non-NULL handle to the LV with 'uuid' attached to the VG.
 * NULL is returned if the LV uuid is not associated with the VG handle.
 */
lv_t lvm_lv_from_uuid(vg_t vg, const char *uuid);

/**
 * Activate a logical volume.
 *
 * \memberof lv_t
 *
 * This function is the equivalent of the lvm command "lvchange -ay".
 *
 * NOTE: This function cannot currently handle LVs with an in-progress pvmove or
 * lvconvert.
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_lv_activate(lv_t lv);

/**
 * Deactivate a logical volume.
 *
 * \memberof lv_t
 *
 * This function is the equivalent of the lvm command "lvchange -an".
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_lv_deactivate(lv_t lv);

/**
 * Remove a logical volume from a volume group.
 *
 * \memberof lv_t
 *
 * This function commits the change to disk and does _not_ require calling
 * lvm_vg_write().
 * NOTE: The commit behavior of this function is subject to change
 * as the API is developed.
 * Currently only removing linear LVs are possible.
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_vg_remove_lv(lv_t lv);

/**
 * Get the current name of a logical volume.
 *
 * \memberof lv_t
 *
 * The memory allocated for the uuid is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * Copy of the uuid string.
 */
const char *lvm_lv_get_uuid(const lv_t lv);

/**
 * Get the current uuid of a logical volume.
 *
 * \memberof lv_t
 *
 * The memory allocated for the name is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * Copy of the name.
 */
const char *lvm_lv_get_name(const lv_t lv);

/**
 * Get the attributes of a logical volume.
 *
 * \memberof lv_t
 *
 * The memory allocated for the name is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * Copy of the attributes for the logical volume
 */
const char *lvm_lv_get_attr(const lv_t lv);

/**
 * Get the origin of a snapshot.
 *
 * \memberof lv_t
 *
 * The memory allocated for the name is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * Null if the logical volume is not a snapshot, else origin name.
 */
const char *lvm_lv_get_origin(const lv_t lv);

/**
 * Get the current size in bytes of a logical volume.
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * Size in bytes.
 */
uint64_t lvm_lv_get_size(const lv_t lv);

/**
 * Get the value of a LV property
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \param   name
 * Name of property to query.  See lvs man page for full list of properties
 * that may be queried.
 *
 * The memory allocated for a string property value is tied to the vg_t
 * handle and will be released when lvm_vg_close() is called.
 *
 * Example:
 *      lvm_property_value v;
 *      char *prop_name = "seg_count";
 *
 *      v = lvm_lv_get_property(lv, prop_name);
 *      if (!v.is_valid) {
 *           printf("Invalid property name or unable to query"
 *                  "'%s', errno = %d.\n", prop_name, lvm_errno(libh));
 *           return;
 *      }
 *      if (v.is_string)
 *           printf(", value = %s\n", v.value.string);
 *	if (v.is_integer)
 *           printf(", value = %"PRIu64"\n", v.value.integer);
 *
 * \return
 * lvm_property_value structure that will contain the current
 * value of the property.  Caller should check 'is_valid' flag before using
 * the value.  If 'is_valid' is not set, caller should check lvm_errno()
 * for specific error.
 */
struct lvm_property_value lvm_lv_get_property(const lv_t lv, const char *name);

/**
 * Get the value of a LV segment property
 *
 * \memberof lv_t
 *
 * \param   lvseg
 * Logical volume segment handle.
 *
 * \param   name
 * Name of property to query.  See lvs man page for full list of properties
 * that may be queried.
 *
 * The memory allocated for a string property value is tied to the vg_t
 * handle and will be released when lvm_vg_close() is called.
 *
 * Example:
 *      lvm_property_value v;
 *      char *prop_name = "seg_start_pe";
 *
 *      v = lvm_lvseg_get_property(lvseg, prop_name);
 *      if (lvm_errno(libh) || !v.is_valid) {
 *           // handle error
 *           printf("Invalid property name or unable to query"
 *                  "'%s'.\n", prop_name);
 *           return;
 *      }
 *      if (v.is_string)
 *           printf(", value = %s\n", v.value.string);
 *	else
 *           printf(", value = %"PRIu64"\n", v.value.integer);
 *
 * \return
 * lvm_property_value structure that will contain the current
 * value of the property.  Caller should check lvm_errno() as well
 * as 'is_valid' flag before using the value.
 */
struct lvm_property_value lvm_lvseg_get_property(const lvseg_t lvseg,
						 const char *name);

/**
 * Get the current activation state of a logical volume.
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * 1 if the LV is active in the kernel, 0 if not
 */
uint64_t lvm_lv_is_active(const lv_t lv);

/**
 * Get the current suspended state of a logical volume.
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \return
 * 1 if the LV is suspended in the kernel, 0 if not
 */
uint64_t lvm_lv_is_suspended(const lv_t lv);

/**
 * Add a tag to an LV.
 *
 * \memberof lv_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully adding a tag, use lvm_vg_write() to commit the
 * new VG to disk.  Upon failure, retry the operation or release the VG handle
 * with lvm_vg_close().
 *
 * \param   lv
 * Logical volume handle.
 *
 * \param   tag
 * Tag to add to an LV.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_lv_add_tag(lv_t lv, const char *tag);

/**
 * Remove a tag from an LV.
 *
 * \memberof lv_t
 *
 * This function requires calling lvm_vg_write() to commit the change to disk.
 * After successfully removing a tag, use lvm_vg_write() to commit the
 * new VG to disk.  Upon failure, retry the operation or release the VG handle
 * with lvm_vg_close().
 *
 * \param   lv
 * Logical volume handle.
 *
 * \param   tag
 * Tag to remove from LV.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_lv_remove_tag(lv_t lv, const char *tag);

/**
 * Return the list of logical volume tags.
 *
 * \memberof lv_t
 *
 * The memory allocated for the list is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * To process the list, use the dm_list iterator functions.  For example:
 *      lv_t lv;
 *      struct dm_list *tags;
 *      struct lvm_str_list *strl;
 *
 *      tags = lvm_lv_get_tags(lv);
 *	dm_list_iterate_items(strl, tags) {
 *		tag = strl->str;
 *              // do something with tag
 *      }
 *
 *
 * \return
 * A list with entries of type struct lvm_str_list, containing the
 * tag strings attached to volume group.
 * If no tags are attached to the LV, an empty list is returned
 * (check with dm_list_empty()).
 * If there is a problem obtaining the list of tags, NULL is returned.
 */
struct dm_list *lvm_lv_get_tags(const lv_t lv);

/**
 * Rename logical volume to new_name.
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \param   new_name
 * New name of logical volume.
 *
 * \return
 * 0 (success) or -1 (failure).
 *
 */
int lvm_lv_rename(lv_t lv, const char *new_name);

/**
 * Resize logical volume to new_size bytes.
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \param   new_size
 * New size in bytes.
 *
 * \return
 * 0 (success) or -1 (failure).
 *
 */
int lvm_lv_resize(const lv_t lv, uint64_t new_size);

/**
 * Create a snapshot of a logical volume
 *
 * \memberof lv_t
 *
 * \param   lv
 * Logical volume handle.
 *
 * \param   snap_name
 * Name of the snapshot.
 *
 * \param   max_snap_size
 * Max snapshot space to use. If you pass zero the same amount of space as
 * the origin will be used.
 *
 * \return
 * Valid lv pointer on success, else NULL on error.
 *
 */
lv_t lvm_lv_snapshot(const lv_t lv, const char *snap_name, uint64_t max_snap_size);

/**
 * Validate a name to be used for LV creation.
 *
 * Validates that the name does not contain any invalid characters, max length
 * and that the LV name doesn't already exist for this VG.
 *
 * Note: You can have the same LV name in different VGs, thus the reason this
 * function requires that you specify a VG to check against.
 *
 * \param lv
 * Volume group handle.
 *
 * \param name
 * Name to validate
 */
int lvm_lv_name_validate(const vg_t vg, const char *lv_name);

/**
 * Thin provisioning discard policies
 */
typedef enum {
	LVM_THIN_DISCARDS_IGNORE,
	LVM_THIN_DISCARDS_NO_PASSDOWN,
	LVM_THIN_DISCARDS_PASSDOWN,
} lvm_thin_discards_t;

/**
 * Create a thinpool parameter passing object for the specified VG
 *
 * \param   vg
 * Volume Group handle.
 *
 * \param   pool_name
 * Name of the pool.
 *
 * \param   size
 * size of the pool
 *
 * \param   chunk_size
 * data block size of the pool
 * Default value is DEFAULT_THIN_POOL_CHUNK_SIZE * 2 when 0 passed as chunk_size
 * DM_THIN_MIN_DATA_BLOCK_SIZE < chunk_size < DM_THIN_MAX_DATA_BLOCK_SIZE
 *
 * \param meta_size
 * Size of thin pool's metadata logical volume. Allowed range is 2MB-16GB.
 * Default value (ie if 0) pool size / pool chunk size * 64
 *
 * \param discard
 * Thin discard policy
 * Note: THIN_DISCARDS_PASSDOWN is the default.
 *
 * \return
 * Valid lv_create_params pointer on success, else NULL on error.
 * Note: Memory is associated with the vg, it will get reclaimed when vg is
 * closed.
 *
 */
lv_create_params_t lvm_lv_params_create_thin_pool(vg_t vg,
		const char *pool_name, uint64_t size, uint32_t chunk_size,
		uint64_t meta_size, lvm_thin_discards_t discard);

#define lvm_lv_params_create_thin_pool_default(vg, pool_name, size) \
			lvm_lv_params_create_thin_pool((vg), (pool_name), (size), 0, 0, \
			LVM_THIN_DISCARDS_PASSDOWN)

/**
 * Creates the snapshot parameter passing object for the specified lv.
 *
 * \param	lv
 * The logical volume to snapshot
 *
 * \param	snap_name
 * Name of snapshot
 *
 * \param	max_snap_size
 * Used for old snap shots max size, set to zero for thinp
 *
 * \return
 * Valid lv_create_params pointer on success, else NULL on error.
 * Note: Memory is associated with the vg, it will get reclaimed when vg is
 * closed.
 */
lv_create_params_t lvm_lv_params_create_snapshot(const lv_t lv,
													const char *snap_name,
													uint64_t max_snap_size);
/**
 * Get the specific value of a lv create parameter by name
 *
 * \param	params		lv create parameters
 *
 * \param	name		name of parameter
 *
 * \return
 * lvm_property_value structure that will contain the current
 * value of the property.  Caller should check 'is_valid' flag before using
 * the value.  If 'is_valid' is not set, caller should check lvm_errno()
 * for specific error.
 */
struct lvm_property_value lvm_lv_params_get_property(
											const lv_create_params_t params,
											const char *name);


/**
 * Set the specific value of a lv create parameter by name
 *
 * Note that the property must be a 'settable' property, as evidenced '
 * by the 'is_settable' flag when querying the property.
 *
 * The memory allocated for a string property value is tied to the vg_t
 * handle associated with the lv_create_params_t and will be released when
 * lvm_vg_close() is called.
 *
 * \param	params		lv create parameters
 *
 * \param	name		name of parameter
 *
 * \param	prop		Property value to use for setting
 *
 * \return
 * 0 on success, -1 on error.
 */
int lvm_lv_params_set_property(lv_create_params_t params,
								const char *name,
								struct lvm_property_value *prop);

/**
 * Create a thin LV creation parameters in a given VG & thin pool
 *
 * \param   vg
 * Volume Group handle.
 *
 * \param   pool_name
 * Name of the pool.
 *
 * \param lvname
 * Name of the LV to create
 *
 * \param   size
 * Size of logical volume
 *
 * \return
 * Valid lv_create_params pointer on success, else NULL on error.
 * Note: Memory is associated with the vg, it will get reclaimed when vg is
 * closed.
 *
 */
lv_create_params_t lvm_lv_params_create_thin(const vg_t vg, const char *pool_name,
									const char *lvname, uint64_t size);
/**
 * Create the actual logical volume.
 *
 * \param	params		The parameters object for lv creation
 *
 * \return
 * Valid lv pointer on success, else NULL on error.
 */
lv_t lvm_lv_create(lv_create_params_t params);

/************************** physical volume handling ************************/

/**
 * Physical volume handling should not be needed anymore. Only physical volumes
 * bound to a vg contain useful information. Therefore the creation,
 * modification and the removal of orphan physical volumes is not suported.
 */

/**
 * Get the current uuid of a physical volume.
 *
 * \memberof pv_t
 *
 * The memory allocated for the uuid is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * Copy of the uuid string.
 */
const char *lvm_pv_get_uuid(const pv_t pv);

/**
 * Get the current name of a physical volume.
 *
 * \memberof pv_t
 *
 * The memory allocated for the name is tied to the vg_t handle and will be
 * released when lvm_vg_close() is called.
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * Copy of the name.
 */
const char *lvm_pv_get_name(const pv_t pv);

/**
 * Get the current number of metadata areas in the physical volume.
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * Number of metadata areas in the PV.
 */
uint64_t lvm_pv_get_mda_count(const pv_t pv);

/**
 * Get the current size in bytes of a device underlying a
 * physical volume.
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * Size in bytes.
 */
uint64_t lvm_pv_get_dev_size(const pv_t pv);

/**
 * Get the current size in bytes of a physical volume.
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * Size in bytes.
 */
uint64_t lvm_pv_get_size(const pv_t pv);

/**
 * Get the current unallocated space in bytes of a physical volume.
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * Free size in bytes.
 */
uint64_t lvm_pv_get_free(const pv_t pv);

/**
 * Get the value of a PV property
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \param   name
 * Name of property to query.  See pvs man page for full list of properties
 * that may be queried.
 *
 * The memory allocated for a string property value is tied to the vg_t handle
 * and will be released when lvm_vg_close() is called. For "percent" values
 * (those obtained for copy_percent and snap_percent properties), please see
 * dm_percent_range_t and lvm_percent_to_float().
 *
 * Example:
 *      lvm_property_value value;
 *      char *prop_name = "pv_mda_count";
 *
 *      v = lvm_pv_get_property(pv, prop_name);
 *      if (!v.is_valid) {
 *           printf("Invalid property name or unable to query"
 *                  "'%s', errno = %d.\n", prop_name, lvm_errno(libh));
 *           return;
 *      }
 *      if (v.is_string)
 *           printf(", value = %s\n", v.value.string);
 *	if (v.is_integer)
 *           printf(", value = %"PRIu64"\n", v.value.integer);
 *
 * \return
 * lvm_property_value structure that will contain the current
 * value of the property.  Caller should check 'is_valid' flag before using
 * the value.  If 'is_valid' is not set, caller should check lvm_errno()
 * for specific error.
 */
struct lvm_property_value lvm_pv_get_property(const pv_t pv, const char *name);

/**
 * Get the value of a PV segment property
 *
 * \memberof pv_t
 *
 * \param   pvseg
 * Physical volume segment handle.
 *
 * \param   name
 * Name of property to query.  See pvs man page for full list of properties
 * that may be queried.
 *
 * The memory allocated for a string property value is tied to the vg_t
 * handle and will be released when lvm_vg_close() is called.
 *
 * Example:
 *      lvm_property_value v;
 *      char *prop_name = "pvseg_start";
 *
 *      v = lvm_pvseg_get_property(pvseg, prop_name);
 *      if (lvm_errno(libh) || !v.is_valid) {
 *           // handle error
 *           printf("Invalid property name or unable to query"
 *                  "'%s'.\n", prop_name);
 *           return;
 *      }
 *      if (v.is_string)
 *           printf(", value = %s\n", v.value.string);
 *	else
 *           printf(", value = %"PRIu64"\n", v.value.integer);
 *
 * \return
 * lvm_property_value structure that will contain the current
 * value of the property.  Caller should check lvm_errno() as well
 * as 'is_valid' flag before using the value.
 */
struct lvm_property_value lvm_pvseg_get_property(const pvseg_t pvseg,
						 const char *name);

/**
 * Return a list of pvseg handles for a given PV handle.
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \return
 * A list of lvm_pvseg_list structures containing pvseg handles for this pv.
 */
struct dm_list *lvm_pv_list_pvsegs(pv_t pv);

/**
 * Lookup an PV handle in a VG by the PV name.
 *
 * \memberof pv_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   name
 * Name of PV to lookup.
 *
 * \return
 * non-NULL handle to the PV 'name' attached to the VG.
 * NULL is returned if the PV name is not associated with the VG handle.
 */
pv_t lvm_pv_from_name(vg_t vg, const char *name);

/**
 * Lookup an PV handle in a VG by the PV uuid.
 * The form of the uuid may be either the formatted, human-readable form,
 * or the non-formatted form.
 *
 * \memberof pv_t
 *
 * \param   vg
 * VG handle obtained from lvm_vg_create() or lvm_vg_open().
 *
 * \param   uuid
 * UUID of PV to lookup.
 *
 * \return
 * non-NULL handle to the PV with 'uuid' attached to the VG.
 * NULL is returned if the PV uuid is not associated with the VG handle.
 */
pv_t lvm_pv_from_uuid(vg_t vg, const char *uuid);

/**
 * Resize physical volume to new_size bytes.
 *
 * \memberof pv_t
 *
 * \param   pv
 * Physical volume handle.
 *
 * \param   new_size
 * New size in bytes.
 *
 * \return
 * 0 (success) or -1 (failure).
 */
int lvm_pv_resize(const pv_t pv, uint64_t new_size);

#define PERCENT_0 DM_PERCENT_0
#define PERCENT_1 DM_PERCENT_1
#define PERCENT_100 DM_PERCENT_100
#define PERCENT_INVALID DM_PERCENT_INVALID
#define PERCENT_MERGE_FAILED DM_PERCENT_FAILED

typedef dm_percent_t percent_t;

/**
 * Convert a (fixed-point) value obtained from the percent-denominated
 * *_get_property functions into a floating-point value.
 */
float lvm_percent_to_float(percent_t v);

#ifdef __cplusplus
}
#endif
#endif /* _LIB_LVM2APP_H */
