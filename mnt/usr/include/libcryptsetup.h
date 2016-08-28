/*
 * libcryptsetup - cryptsetup library
 *
 * Copyright (C) 2004, Jana Saout <jana@saout.de>
 * Copyright (C) 2004-2007, Clemens Fruhwirth <clemens@endorphin.org>
 * Copyright (C) 2009-2016, Red Hat, Inc. All rights reserved.
 * Copyright (C) 2009-2016, Milan Broz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * @file libcryptsetup.h
 * @brief Public cryptsetup API
 *
 * For more verbose examples of LUKS related use cases,
 * please read @ref index "examples".
 */

#ifndef _LIBCRYPTSETUP_H
#define _LIBCRYPTSETUP_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

struct crypt_device; /* crypt device handle */

/**
 * Initialize crypt device handle and check if provided device exists.
 *
 * @param cd Returns pointer to crypt device handle
 * @param device Path to the backing device.
 * 	  If @e device is not a block device but a path to some file,
 * 	  the function will try to create a loopdevice and attach
 * 	  the file to the loopdevice with AUTOCLEAR flag set.
 * 	  If @e device is @e NULL function it will initialize dm backend only.
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note Note that logging is not initialized here, possible messages uses
 * 	 default log function.
 */
int crypt_init(struct crypt_device **cd, const char *device);

/**
 * Initialize crypt device handle from provided active device name,
 * and, optionally, from separate metadata (header) device
 * and check if provided device exists.
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @param cd returns crypt device handle for active device
 * @param name name of active crypt device
 * @param header_device optional device containing on-disk header
 * 	  (@e NULL if it the same as underlying device on there is no on-disk header)
 *
 * @post In case @e device points to active LUKS device but header load fails,
 * context device type is set to @e NULL and @e 0 is returned as if it were successful.
 * Context with @e NULL device type can only be deactivated by crypt_deactivate
 *
 * @note @link crypt_init_by_name @endlink is equivalent to calling
 * 	 crypt_init_by_name_and_header(cd, name, NULL);
 */
int crypt_init_by_name_and_header(struct crypt_device **cd,
				  const char *name,
				  const char *header_device);

/**
 * This is equivalent to call
 * @ref crypt_init_by_name_and_header "crypt_init_by_name_and_header(cd, name, NULL)"
 *
 * @sa crypt_init_by_name_and_header
 */
int crypt_init_by_name(struct crypt_device **cd, const char *name);

/**
 * @defgroup loglevel Cryptsetup logging
 *
 * Set of functions and defines used in cryptsetup for
 * logging purposes
 *
 */

/**
 * @addtogroup loglevel
 * @{
 */

/** normal log level */
#define CRYPT_LOG_NORMAL 0
/** error log level */
#define CRYPT_LOG_ERROR  1
/** verbose log level */
#define CRYPT_LOG_VERBOSE  2
/** debug log level - always on stdout */
#define CRYPT_LOG_DEBUG -1

/**
 * Set log function.
 *
 * @param cd crypt device handle (can be @e NULL to set default log function)
 * @param log user defined log function reference
 * @param usrptr provided identification in callback
 * @param level log level below (debug messages can uses other levels)
 * @param msg log message
 */
void crypt_set_log_callback(struct crypt_device *cd,
	void (*log)(int level, const char *msg, void *usrptr),
	void *usrptr);

/**
 * Defines log function or use the default one otherwise.
 *
 * @see crypt_set_log_callback
 *
 * @param cd crypt device handle
 * @param level log level
 * @param msg log message
 */
void crypt_log(struct crypt_device *cd, int level, const char *msg);
/** @} */

/**
 * Set confirmation callback (yes/no).
 *
 * If code need confirmation (like resetting uuid or restoring LUKS header from file)
 * this function is called. If not defined, everything is confirmed.
 *
 * Callback function @e confirm should return @e 0 if operation is declined,
 * other values mean accepted.
 *
 * @param cd crypt device handle
 * @param confirm user defined confirm callback reference
 * @param usrptr provided identification in callback
 * @param msg Message for user to confirm
 *
 * @note Current version of cryptsetup API requires confirmation only when UUID is being changed
 */
void crypt_set_confirm_callback(struct crypt_device *cd,
	int (*confirm)(const char *msg, void *usrptr),
	void *usrptr);

/**
 * Set password query callback. DEPRECATED
 *
 * If code need @e _interactive_ query for password, this callback is called.
 * If not defined, compiled-in default is called (uses terminal input).
 *
 * Callback should return length of password in buffer
 * or negative errno value in case of error.
 *
 * @param cd crypt device handle
 * @param password user defined password callback reference
 * @param usrptr provided identification in callback
 * @param msg Message for user
 * @param buf buffer for password
 * @param length size of buffer
 *
 * @note Note that if this function is defined, verify option is ignored
 *   (caller which provided callback is responsible for password verification)
 * @note Only zero terminated passwords can be entered this way, for complex
 *   use API functions directly.
 * @note Maximal length of password is limited to @e length @e - @e 1 (minimal 511 chars)
 * @note This function is DEPRECATED and will be removed in future versions.
 *
 * @see Callback function is used in these call provided, that certain conditions are met:
 * @li crypt_keyslot_add_by_passphrase
 * @li crypt_activate_by_passphrase
 * @li crypt_resume_by_passphrase
 * @li crypt_resume_by_keyfile
 * @li crypt_keyslot_add_by_keyfile
 * @li crypt_keyslot_add_by_volume_key
 *
 */
void crypt_set_password_callback(struct crypt_device *cd,
	int (*password)(const char *msg, char *buf, size_t length, void *usrptr),
	void *usrptr);

/**
 * Set timeout for interactive password entry using default
 * password callback. DEPRECATED
 *
 * @param cd crypt device handle
 * @param timeout_sec timeout in seconds
 */
void crypt_set_timeout(struct crypt_device *cd, uint64_t timeout_sec);

/**
 * Set number of retries in case password input has been incorrect. DEPRECATED.
 *
 * @param cd crypt device handle
 * @param tries the number
 *
 * @note This function is DEPRECATED and will be removed in future versions.
 */
void crypt_set_password_retry(struct crypt_device *cd, int tries);

/**
 * Set how long should cryptsetup iterate in PBKDF2 function.
 * Default value heads towards the iterations which takes around 1 second.
 *
 * @param cd crypt device handle
 * @param iteration_time_ms the time in ms
 */
void crypt_set_iteration_time(struct crypt_device *cd, uint64_t iteration_time_ms);
/* Don't ask :-) */
void crypt_set_iterarion_time(struct crypt_device *cd, uint64_t iteration_time_ms);

/**
 * Set whether passphrase will be verified on input
 * (user has to input same passphrase twice). DEPRECATED
 *
 * @param cd crypt device handle
 * @param password_verify @e 0 = false, @e !0 true
 *
 * @note This function is DEPRECATED and will be removed in future versions.
 */
void crypt_set_password_verify(struct crypt_device *cd, int password_verify);

/**
 * Set data device
 * For LUKS it is encrypted data device when LUKS header is separated.
 * For VERITY it is data device when hash device is separated.
 *
 * @param cd crypt device handle
 * @param device path to device
 *
 */
int crypt_set_data_device(struct crypt_device *cd, const char *device);

/**
 * @defgroup rng Cryptsetup RNG
 *
 * @addtogroup rng
 * @{
 *
 */

/** CRYPT_RNG_URANDOM - use /dev/urandom */
#define CRYPT_RNG_URANDOM 0
/** CRYPT_RNG_RANDOM  - use /dev/random (waits if no entropy in system) */
#define CRYPT_RNG_RANDOM  1

/**
 * Set which RNG (random number generator) is used for generating long term key
 *
 * @param cd crypt device handle
 * @param rng_type kernel random number generator to use
 *
 */
void crypt_set_rng_type(struct crypt_device *cd, int rng_type);

/**
 * Get which RNG (random number generator) is used for generating long term key.
 *
 * @param cd crypt device handle
 * @return RNG type on success or negative errno value otherwise.
 *
 */
int crypt_get_rng_type(struct crypt_device *cd);

/** @} */

/**
 * Helper to lock/unlock memory to avoid swap sensitive data to disk.
 *
 * @param cd crypt device handle, can be @e NULL
 * @param lock 0 to unlock otherwise lock memory
 *
 * @returns Value indicating whether the memory is locked (function can be called multiple times).
 *
 * @note Only root can do this.
 * @note It locks/unlocks all process memory, not only crypt context.
 */
int crypt_memory_lock(struct crypt_device *cd, int lock);

/**
 * @defgroup crypt_type Cryptsetup on-disk format types
 *
 * Set of functions, \#defines and structs related
 * to on-disk format types
 */

/**
 * @addtogroup crypt_type
 * @{
 */

/** plain crypt device, no on-disk header */
#define CRYPT_PLAIN "PLAIN"
/** LUKS version 1 header on-disk */
#define CRYPT_LUKS1 "LUKS1"
/** loop-AES compatibility mode */
#define CRYPT_LOOPAES "LOOPAES"
/** dm-verity mode */
#define CRYPT_VERITY "VERITY"
/** TCRYPT (TrueCrypt-compatible and VeraCrypt-compatible) mode */
#define CRYPT_TCRYPT "TCRYPT"

/**
 * Get device type
 *
 * @param cd crypt device handle
 * @return string according to device type or @e NULL if not known.
 */
const char *crypt_get_type(struct crypt_device *cd);

/**
 *
 * Structure used as parameter for PLAIN device type.
 *
 * @see crypt_format
 */
struct crypt_params_plain {
	const char *hash; /**< password hash function */
	uint64_t offset; /**< offset in sectors */
	uint64_t skip; /**< IV offset / initialization sector */
	uint64_t size; /**< size of mapped device or @e 0 for autodetection */
};

/**
 * Structure used as parameter for LUKS device type.
 *
 * @see crypt_format, crypt_load
 *
 * @note during crypt_format @e data_device attribute determines
 * 	 if the LUKS header is separated from encrypted payload device
 *
 */
struct crypt_params_luks1 {
	const char *hash; /**< hash used in LUKS header */
	size_t data_alignment; /**< data alignment in sectors, data offset is multiple of this */
	const char *data_device; /**< detached encrypted data device or @e NULL */
};

/**
 *
 * Structure used as parameter for loop-AES device type.
 *
 * @see crypt_format
 *
 */
struct crypt_params_loopaes {
	const char *hash; /**< key hash function */
	uint64_t offset;  /**< offset in sectors */
	uint64_t skip;    /**< IV offset / initialization sector */
};

/**
 *
 * Structure used as parameter for dm-verity device type.
 *
 * @see crypt_format, crypt_load
 *
 */
struct crypt_params_verity {
	const char *hash_name;     /**< hash function */
	const char *data_device;   /**< data_device (CRYPT_VERITY_CREATE_HASH) */
	const char *hash_device;   /**< hash_device (output only) */
	const char *salt;          /**< salt */
	uint32_t salt_size;        /**< salt size (in bytes) */
	uint32_t hash_type;        /**< in-kernel hashing type */
	uint32_t data_block_size;  /**< data block size (in bytes) */
	uint32_t hash_block_size;  /**< hash block size (in bytes) */
	uint64_t data_size;        /**< data area size (in data blocks) */
	uint64_t hash_area_offset; /**< hash/header offset (in bytes) */
	uint32_t flags;            /**< CRYPT_VERITY* flags */
};

/** No on-disk header (only hashes) */
#define CRYPT_VERITY_NO_HEADER   (1 << 0)
/** Verity hash in userspace before activation */
#define CRYPT_VERITY_CHECK_HASH  (1 << 1)
/** Create hash - format hash device */
#define CRYPT_VERITY_CREATE_HASH (1 << 2)

/**
 *
 * Structure used as parameter for TCRYPT device type.
 *
 * @see crypt_load
 *
 */
struct crypt_params_tcrypt {
	const char *passphrase;    /**< passphrase to unlock header (input only) */
	size_t passphrase_size;    /**< passphrase size (input only, max length is 64) */
	const char **keyfiles;     /**< keyfile paths to unlock header (input only) */
	unsigned int keyfiles_count;/**< keyfiles count (input only) */
	const char *hash_name;     /**< hash function for PBKDF */
	const char *cipher;        /**< cipher chain c1[-c2[-c3]] */
	const char *mode;          /**< cipher block mode */
	size_t key_size;           /**< key size in bytes (the whole chain) */
	uint32_t flags;            /**< CRYPT_TCRYPT* flags */
};

/** Include legacy modes when scanning for header */
#define CRYPT_TCRYPT_LEGACY_MODES    (1 << 0)
/** Try to load hidden header (describing hidden device) */
#define CRYPT_TCRYPT_HIDDEN_HEADER   (1 << 1)
/** Try to load backup header */
#define CRYPT_TCRYPT_BACKUP_HEADER   (1 << 2)
/** Device contains encrypted system (with boot loader) */
#define CRYPT_TCRYPT_SYSTEM_HEADER   (1 << 3)
/** Include VeraCrypt modes when scanning for header,
 *  all other TCRYPT flags applies as well.
 *  VeraCrypt device is reported as TCRYPT type.
 */
#define CRYPT_TCRYPT_VERA_MODES      (1 << 4)

/** @} */

/**
 * Create (format) new crypt device (and possible header on-disk) but do not activate it.
 *
 * @pre @e cd contains initialized and not formatted device context (device type must @b not be set)
 *
 * @param cd crypt device handle
 * @param type type of device (optional params struct must be of this type)
 * @param cipher (e.g. "aes")
 * @param cipher_mode including IV specification (e.g. "xts-plain")
 * @param uuid requested UUID or @e NULL if it should be generated
 * @param volume_key pre-generated volume key or @e NULL if it should be generated (only for LUKS)
 * @param volume_key_size size of volume key in bytes.
 * @param params crypt type specific parameters (see @link crypt_type @endlink)
 *
 * @returns @e 0 on success or negative errno value otherwise.
 *
 * @note Note that crypt_format does not enable any keyslot (in case of work with LUKS device),
 * 	but it stores volume key internally and subsequent crypt_keyslot_add_* calls can be used.
 * @note For VERITY @link crypt_type @endlink, only uuid parameter is used, others paramaters
 * 	are ignored and verity specific attributes are set through mandatory params option.
 */
int crypt_format(struct crypt_device *cd,
	const char *type,
	const char *cipher,
	const char *cipher_mode,
	const char *uuid,
	const char *volume_key,
	size_t volume_key_size,
	void *params);

/**
 * Set new UUID for already existing device.
 *
 * @param cd crypt device handle
 * @param uuid requested UUID or @e NULL if it should be generated
 *
 * @returns 0 on success or negative errno value otherwise.
 *
 * @note Currently, only LUKS device type are supported
 */
int crypt_set_uuid(struct crypt_device *cd,
		   const char *uuid);

/**
 * Load crypt device parameters from on-disk header.
 *
 * @param cd crypt device handle
 * @param requested_type @link crypt_type @endlink or @e NULL for all known
 * @param params crypt type specific parameters (see @link crypt_type @endlink)
 *
 * @returns 0 on success or negative errno value otherwise.
 *
 * @post In case LUKS header is read successfully but payload device is too small
 * error is returned and device type in context is set to @e NULL
 *
 * @note Note that in current version load works only for LUKS and VERITY device type.
 *
 */
int crypt_load(struct crypt_device *cd,
	       const char *requested_type,
	       void *params);

/**
 * Try to repair crypt device on-disk header if invalid.
 *
 * @param cd crypt device handle
 * @param requested_type @link crypt_type @endlink or @e NULL for all known
 * @param params crypt type specific parameters (see @link crypt_type @endlink)
 *
 * @returns 0 on success or negative errno value otherwise.
 *
 */
int crypt_repair(struct crypt_device *cd,
		 const char *requested_type,
		 void *params);

/**
 * Resize crypt device.
 *
 * @param cd - crypt device handle
 * @param name - name of device to resize
 * @param new_size - new device size in sectors or @e 0 to use all of the underlying device size
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_resize(struct crypt_device *cd,
		 const char *name,
		 uint64_t new_size);

/**
 * Suspend crypt device.
 *
 * @param cd crypt device handle, can be @e NULL
 * @param name name of device to suspend
 *
 * @return 0 on success or negative errno value otherwise.
 *
 * @note Only LUKS device type is supported
 *
 */
int crypt_suspend(struct crypt_device *cd,
		  const char *name);

/**
 * Resume crypt device using passphrase.
 *
 *
 * @param cd crypt device handle
 * @param name name of device to resume
 * @param keyslot requested keyslot or CRYPT_ANY_SLOT
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of @e passphrase (binary data)
 *
 * @return unlocked key slot number or negative errno otherwise.
 *
 * @note Only LUKS device type is supported
 * @note If passphrase is @e NULL always use crypt_set_password_callback.
 * Internal terminal password query is DEPRECATED and will be removed in next version.
 */
int crypt_resume_by_passphrase(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *passphrase,
	size_t passphrase_size);

/**
 * Resume crypt device using key file.
 *
 * @param cd crypt device handle
 * @param name name of device to resume
 * @param keyslot requested keyslot or CRYPT_ANY_SLOT
 * @param keyfile key file used to unlock volume key, @e NULL for passphrase query
 * @param keyfile_size number of bytes to read from keyfile, 0 is unlimited
 * @param keyfile_offset number of bytes to skip at start of keyfile
 *
 * @return unlocked key slot number or negative errno otherwise.
 *
 * @note If passphrase is @e NULL always use crypt_set_password_callback.
 * Internal terminal password query is DEPRECATED and will be removed in next version.
 */
int crypt_resume_by_keyfile_offset(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	size_t keyfile_offset);
/**
 * Backward compatible crypt_resume_by_keyfile_offset() (without offset).
 */
int crypt_resume_by_keyfile(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size);

/**
 * Release crypt device context and used memory.
 *
 * @param cd crypt device handle
 */
void crypt_free(struct crypt_device *cd);

/**
 * @defgroup keyslot Cryptsetup LUKS keyslots
 * @addtogroup keyslot
 * @{
 *
 */

/** iterate through all keyslots and find first one that fits */
#define CRYPT_ANY_SLOT -1

/**
 * Add key slot using provided passphrase.
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot or @e CRYPT_ANY_SLOT
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of passphrase (binary data)
 * @param new_passphrase passphrase for new keyslot, @e NULL for query
 * @param new_passphrase_size size of @e new_passphrase (binary data)
 *
 * @return allocated key slot number or negative errno otherwise.
 *
 * @note If passphrase is @e NULL always use crypt_set_password_callback.
 * Internal terminal password query is DEPRECATED and will be removed in next version.
 */
int crypt_keyslot_add_by_passphrase(struct crypt_device *cd,
	int keyslot,
	const char *passphrase,
	size_t passphrase_size,
	const char *new_passphrase,
	size_t new_passphrase_size);

/**
 * Change defined key slot using provided passphrase.
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot_old old keyslot or @e CRYPT_ANY_SLOT
 * @param keyslot_new new keyslot (can be the same as old)
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of passphrase (binary data)
 * @param new_passphrase passphrase for new keyslot, @e NULL for query
 * @param new_passphrase_size size of @e new_passphrase (binary data)
 *
 * @return allocated key slot number or negative errno otherwise.
 *
 * @note This function is just internal implementation of luksChange
 * command to avoid reading of volume key outside libcryptsetup boundary
 * in FIPS mode.
 *
 * @note If passphrase is @e NULL always use crypt_set_password_callback.
 * Internal terminal password query is DEPRECATED and will be removed in next version.
 */
int crypt_keyslot_change_by_passphrase(struct crypt_device *cd,
	int keyslot_old,
	int keyslot_new,
	const char *passphrase,
	size_t passphrase_size,
	const char *new_passphrase,
	size_t new_passphrase_size);

/**
* Add key slot using provided key file path.
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot or @e CRYPT_ANY_SLOT
 * @param keyfile key file used to unlock volume key, @e NULL for passphrase query
 * @param keyfile_size number of bytes to read from keyfile, @e 0 is unlimited
 * @param keyfile_offset number of bytes to skip at start of keyfile
 * @param new_keyfile keyfile for new keyslot, @e NULL for passphrase query
 * @param new_keyfile_size number of bytes to read from @e new_keyfile, @e 0 is unlimited
 * @param new_keyfile_offset number of bytes to skip at start of new_keyfile
 *
 * @return allocated key slot number or negative errno otherwise.
 *
 * @note Note that @e keyfile can be "-" for STDIN. This special handling is DEPRECATED
 * and will be removed in next version.
 */
int crypt_keyslot_add_by_keyfile_offset(struct crypt_device *cd,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	size_t keyfile_offset,
	const char *new_keyfile,
	size_t new_keyfile_size,
	size_t new_keyfile_offset);
/**
 * Backward compatible crypt_keyslot_add_by_keyfile_offset() (without offset).
 */
int crypt_keyslot_add_by_keyfile(struct crypt_device *cd,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	const char *new_keyfile,
	size_t new_keyfile_size);

/**
 * Add key slot using provided volume key.
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot or CRYPT_ANY_SLOT
 * @param volume_key provided volume key or @e NULL if used after crypt_format
 * @param volume_key_size size of volume_key
 * @param passphrase passphrase for new keyslot, @e NULL for query
 * @param passphrase_size size of passphrase
 *
 * @return allocated key slot number or negative errno otherwise.
 *
 * @note If passphrase is @e NULL always use crypt_set_password_callback.
 * Internal terminal password query is DEPRECATED and will be removed in next version.
 */
int crypt_keyslot_add_by_volume_key(struct crypt_device *cd,
	int keyslot,
	const char *volume_key,
	size_t volume_key_size,
	const char *passphrase,
	size_t passphrase_size);

/**
 * Destroy (and disable) key slot.
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested key slot to destroy
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note Note that there is no passphrase verification used.
 */
int crypt_keyslot_destroy(struct crypt_device *cd, int keyslot);

/** @} */

/**
 * @defgroup aflags Device runtime attributes
 *
 * Activation flags
 *
 * @addtogroup aflags
 * @{
 *
 */
/** device is read only */
#define CRYPT_ACTIVATE_READONLY (1 << 0)
/** only reported for device without uuid */
#define CRYPT_ACTIVATE_NO_UUID  (1 << 1)
/** activate even if cannot grant exclusive access (DANGEROUS) */
#define CRYPT_ACTIVATE_SHARED   (1 << 2)
/** enable discards aka TRIM */
#define CRYPT_ACTIVATE_ALLOW_DISCARDS (1 << 3)
/** skip global udev rules in activation ("private device"), input only */
#define CRYPT_ACTIVATE_PRIVATE (1 << 4)
/** corruption detected (verity), output only */
#define CRYPT_ACTIVATE_CORRUPTED (1 << 5)
/** use same_cpu_crypt option for dm-crypt */
#define CRYPT_ACTIVATE_SAME_CPU_CRYPT (1 << 6)
/** use submit_from_crypt_cpus for dm-crypt */
#define CRYPT_ACTIVATE_SUBMIT_FROM_CRYPT_CPUS (1 << 7)
/** dm-verity: ignore_corruption flag - ignore corruption, log it only */
#define CRYPT_ACTIVATE_IGNORE_CORRUPTION (1 << 8)
/** dm-verity: restart_on_corruption flag - restart kernel on corruption */
#define CRYPT_ACTIVATE_RESTART_ON_CORRUPTION (1 << 9)
/** dm-verity: ignore_zero_blocks - do not verify zero blocks */
#define CRYPT_ACTIVATE_IGNORE_ZERO_BLOCKS (1 << 10)


/**
 * Active device runtime attributes
 */
struct crypt_active_device {
	uint64_t offset; /**< offset in sectors */
	uint64_t iv_offset; /**< IV initialization sector */
	uint64_t size; /**< active device size */
	uint32_t flags; /**< activation flags */
};

/**
 * Receive runtime attributes of active crypt device.
 *
 * @param cd crypt device handle (can be @e NULL)
 * @param name name of active device
 * @param cad preallocated active device attributes to fill
 *
 * @return @e 0 on success or negative errno value otherwise
 *
 */
int crypt_get_active_device(struct crypt_device *cd,
			    const char *name,
			    struct crypt_active_device *cad);

/** @} */

/**
 * Activate device or check passphrase.
 *
 * @param cd crypt device handle
 * @param name name of device to create, if @e NULL only check passphrase
 * @param keyslot requested keyslot to check or @e CRYPT_ANY_SLOT
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of @e passphrase
 * @param flags activation flags
 *
 * @return unlocked key slot number or negative errno otherwise.
 *
 * @note If passphrase is @e NULL always use crypt_set_password_callback.
 * Internal terminal password query is DEPRECATED and will be removed in next version.
 */
int crypt_activate_by_passphrase(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *passphrase,
	size_t passphrase_size,
	uint32_t flags);

/**
 * Activate device or check using key file.
 *
 * @param cd crypt device handle
 * @param name name of device to create, if @e NULL only check keyfile
 * @param keyslot requested keyslot to check or CRYPT_ANY_SLOT
 * @param keyfile key file used to unlock volume key
 * @param keyfile_size number of bytes to read from keyfile, 0 is unlimited
 * @param keyfile_offset number of bytes to skip at start of keyfile
 * @param flags activation flags
 *
 * @return unlocked key slot number or negative errno otherwise.
 */
int crypt_activate_by_keyfile_offset(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	size_t keyfile_offset,
	uint32_t flags);
/**
 * Backward compatible crypt_activate_by_keyfile_offset() (without offset).
 */
int crypt_activate_by_keyfile(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	uint32_t flags);

/**
 * Activate device using provided volume key.
 *
 *
 * @param cd crypt device handle
 * @param name name of device to create, if @e NULL only check volume key
 * @param volume_key provided volume key (or @e NULL to use internal)
 * @param volume_key_size size of volume_key
 * @param flags activation flags
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note If @e NULL is used for volume_key, device has to be initialized
 * 	 by previous operation (like @ref crypt_format
 * 	 or @ref crypt_init_by_name)
 * @note For VERITY the volume key means root hash required for activation.
 * 	 Because kernel dm-verity is always read only, you have to provide
 * 	 CRYPT_ACTIVATE_READONLY flag always.
 * @note For TCRYPT the volume key should be always NULL and because master
 * 	 key from decrypted header is used instead.
 */
int crypt_activate_by_volume_key(struct crypt_device *cd,
	const char *name,
	const char *volume_key,
	size_t volume_key_size,
	uint32_t flags);

/**
 * Deactivate crypt device. This function tries to remove active device-mapper
 * mapping from kernel. Also, sensitive data like the volume key are removed from
 * memory
 *
 * @param cd crypt device handle, can be @e NULL
 * @param name name of device to deactivate
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_deactivate(struct crypt_device *cd, const char *name);

/**
 * Get volume key from crypt device.
 *
 * @param cd crypt device handle
 * @param keyslot use this keyslot or @e CRYPT_ANY_SLOT
 * @param volume_key buffer for volume key
 * @param volume_key_size on input, size of buffer @e volume_key,
 *        on output size of @e volume_key
 * @param passphrase passphrase used to unlock volume key
 * @param passphrase_size size of @e passphrase
 *
 * @return unlocked key slot number or negative errno otherwise.
 *
 * @note For TCRYPT cipher chain is  the volume key concatenated
 * 	 for all ciphers in chain.
 */
int crypt_volume_key_get(struct crypt_device *cd,
	int keyslot,
	char *volume_key,
	size_t *volume_key_size,
	const char *passphrase,
	size_t passphrase_size);

/**
 * Verify that provided volume key is valid for crypt device.
 *
 * @param cd crypt device handle
 * @param volume_key provided volume key
 * @param volume_key_size size of @e volume_key
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_volume_key_verify(struct crypt_device *cd,
	const char *volume_key,
	size_t volume_key_size);

/**
 * @defgroup devstat Crypt and Verity device status
 * @addtogroup devstat
 * @{
 */

/**
 * Device status
 */
typedef enum {
	CRYPT_INVALID, /**< device mapping is invalid in this context */
	CRYPT_INACTIVE, /**< no such mapped device */
	CRYPT_ACTIVE, /**< device is active */
	CRYPT_BUSY /**< device is active and has open count > 0 */
} crypt_status_info;

/**
 * Get status info about device name.
 *
 * @param cd crypt device handle, can be @e NULL
 * @param name crypt device name
 *
 * @return value defined by crypt_status_info.
 *
 */
crypt_status_info crypt_status(struct crypt_device *cd, const char *name);

/**
 * Dump text-formatted information about crypt or verity device to log output.
 *
 * @param cd crypt device handle
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_dump(struct crypt_device *cd);

/**
 * Get cipher used in device.
 *
 * @param cd crypt device handle
 *
 * @return used cipher, e.g. "aes" or @e NULL otherwise
 *
 */
const char *crypt_get_cipher(struct crypt_device *cd);

/**
 * Get cipher mode used in device.
 *
 * @param cd crypt device handle
 *
 * @return used cipher mode e.g. "xts-plain" or @e otherwise
 *
 */
const char *crypt_get_cipher_mode(struct crypt_device *cd);

/**
 * Get device UUID.
 *
 * @param cd crypt device handle
 *
 * @return device UUID or @e NULL if not set
 *
 */
const char *crypt_get_uuid(struct crypt_device *cd);

/**
 * Get path to underlaying device.
 *
 * @param cd crypt device handle
 *
 * @return path to underlaying device name
 *
 */
const char *crypt_get_device_name(struct crypt_device *cd);

/**
 * Get device offset in sectors where real data starts (on underlying device).
 *
 * @param cd crypt device handle
 *
 * @return device offset in sectors
 *
 */
uint64_t crypt_get_data_offset(struct crypt_device *cd);

/**
 * Get IV offset in sectors (skip).
 *
 * @param cd crypt device handle
 *
 * @return IV offset
 *
 */
uint64_t crypt_get_iv_offset(struct crypt_device *cd);

/**
 * Get size (in bytes) of volume key for crypt device.
 *
 * @param cd crypt device handle
 *
 * @return volume key size
 *
 */
int crypt_get_volume_key_size(struct crypt_device *cd);

/**
 * Get device parameters for VERITY device.
 *
 * @param cd crypt device handle
 * @param vp verity device info
 *
 * @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_get_verity_info(struct crypt_device *cd,
	struct crypt_params_verity *vp);
/** @} */

/**
 * @defgroup benchmark Benchmarking
 *
 * Benchmarking of algorithms
 *
 * @addtogroup benchmark
 * @{
 *
 */

/**
 * Informational benchmark for ciphers.
 *
 * @param cd crypt device handle
 * @param cipher (e.g. "aes")
 * @param cipher_mode (e.g. "xts"), IV generator is ignored
 * @param volume_key_size size of volume key in bytes
 * @param iv_size size of IV in bytes
 * @param buffer_size size of encryption buffer in bytes used in test
 * @param encryption_mbs measured encryption speed in MiB/s
 * @param decryption_mbs measured decryption speed in MiB/s
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note If encryption_buffer_size is too small and encryption time
 *       cannot be properly measured, -ERANGE is returned.
 */
int crypt_benchmark(struct crypt_device *cd,
	const char *cipher,
	const char *cipher_mode,
	size_t volume_key_size,
	size_t iv_size,
	size_t buffer_size,
	double *encryption_mbs,
	double *decryption_mbs);

/**
 * Informational benchmark for KDF.
 *
 * @param cd crypt device handle
 * @param kdf Key derivation function (e.g. "pbkdf2")
 * @param hash Hash algorithm used in KDF (e.g. "sha256")
 * @param password password for benchmark
 * @param password_size size of password
 * @param salt salt for benchmark
 * @param salt_size size of salt
 * @param iterations_sec returns measured KDF iterations per second
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_benchmark_kdf(struct crypt_device *cd,
	const char *kdf,
	const char *hash,
	const char *password,
	size_t password_size,
	const char *salt,
	size_t salt_size,
	uint64_t *iterations_sec);
/** @} */

/**
 * @addtogroup keyslot
 * @{
 *
 */

/**
 * Crypt keyslot info
 */
typedef enum {
	CRYPT_SLOT_INVALID, /**< invalid keyslot */
	CRYPT_SLOT_INACTIVE, /**< keyslot is inactive (free) */
	CRYPT_SLOT_ACTIVE, /**< keyslot is active (used) */
	CRYPT_SLOT_ACTIVE_LAST /**< keylost is active (used)
				*   and last used at the same time */
} crypt_keyslot_info;

/**
 * Get information about particular key slot.
 *
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot to check or CRYPT_ANY_SLOT
 *
 * @return value defined by crypt_keyslot_info
 *
 */
crypt_keyslot_info crypt_keyslot_status(struct crypt_device *cd, int keyslot);
/** @} */

/**
 * Get number of keyslots supported for device type.
 *
 * @param type crypt device type
 *
 * @return slot count or negative errno otherwise if device
 * doesn't not support keyslots.
 */
int crypt_keyslot_max(const char *type);

/**
 * Get keyslot area pointers (relative to metadata device).
 *
 * @param cd crypt device handle
 * @param keyslot keyslot number
 * @param offset offset on metadata device (in bytes)
 * @param length length of keyslot area (in bytes)
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_keyslot_area(struct crypt_device *cd,
	int keyslot,
	uint64_t *offset,
	uint64_t *length);

/**
 * Backup header and keyslots to file.
 *
 * @param cd crypt device handle
 * @param requested_type @link crypt_type @endlink or @e NULL for all known
 * @param backup_file file to backup header to
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_header_backup(struct crypt_device *cd,
	const char *requested_type,
	const char *backup_file);

/**
 * Restore header and keyslots from backup file.
 *
 *
 * @param cd crypt device handle
 * @param requested_type @link crypt_type @endlink or @e NULL for all known
 * @param backup_file file to restore header from
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_header_restore(struct crypt_device *cd,
	const char *requested_type,
	const char *backup_file);

/**
 * Receive last reported error, DEPRECATED.
 *
 * @param cd crypt device handle
 * @param buf buffef for message
 * @param size size of buffer
 *
 * @note This function is DEPRECATED and will be removed in future versions.
 * @note All error messages are reported also through log callback.
 */
void crypt_last_error(struct crypt_device *cd, char *buf, size_t size);

/**
 * Receives last reported error, DEPRECATED
 *
 * @param buf buffef for message
 * @param size size of buffer
 *
 * @note This function is DEPRECATED and will be removed in future versions.
 */
void crypt_get_error(char *buf, size_t size);

/**
 * Get directory where mapped crypt devices are created
 *
 * @return the directory path
 */
const char *crypt_get_dir(void);

/**
 * @defgroup dbg Library debug level
 *
 * Set library debug level
 *
 * @addtogroup dbg
 * @{
 */

/** Debug all */
#define CRYPT_DEBUG_ALL  -1
/** Debug none */
#define CRYPT_DEBUG_NONE  0

/**
 * Set the debug level for library
 *
 * @param level debug level
 *
 */
void crypt_set_debug_level(int level);

/** @} */

#ifdef __cplusplus
}
#endif
#endif /* _LIBCRYPTSETUP_H */
