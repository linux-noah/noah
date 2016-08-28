/* ksba.h - X.509 library used by GnuPG
 * Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2010, 2011
 *               2012, 2013, 2104, 2015 g10 Code GmbH
 *
 * This file is part of KSBA.
 *
 * KSBA is free software; you can redistribute it and/or modify
 * it under the terms of either
 *
 *   - the GNU Lesser General Public License as published by the Free
 *     Software Foundation; either version 3 of the License, or (at
 *     your option) any later version.
 *
 * or
 *
 *   - the GNU General Public License as published by the Free
 *     Software Foundation; either version 2 of the License, or (at
 *     your option) any later version.
 *
 * or both in parallel, as here.
 *
 * KSBA is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copies of the GNU General Public License
 * and the GNU Lesser General Public License along with this program;
 * if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KSBA_H
#define KSBA_H 1

#include <gpg-error.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#if 0
 }
#endif
#endif


/* Check for compiler features.  */
#ifdef __GNUC__
#define _KSBA_GCC_VERSION (__GNUC__ * 10000 \
                            + __GNUC_MINOR__ * 100 \
                            + __GNUC_PATCHLEVEL__)
#if _KSBA_GCC_VERSION > 30100
#define _KSBA_DEPRECATED	__attribute__ ((__deprecated__))
#endif
#endif /*__GNUC__*/

#ifndef _KSBA_DEPRECATED
#define _KSBA_DEPRECATED
#endif


typedef gpg_error_t KsbaError _KSBA_DEPRECATED;

typedef enum
  {
    KSBA_CT_NONE = 0,
    KSBA_CT_DATA = 1,
    KSBA_CT_SIGNED_DATA = 2,
    KSBA_CT_ENVELOPED_DATA = 3,
    KSBA_CT_DIGESTED_DATA = 4,
    KSBA_CT_ENCRYPTED_DATA = 5,
    KSBA_CT_AUTH_DATA = 6,
    KSBA_CT_PKCS12 = 7
  }
ksba_content_type_t;
typedef ksba_content_type_t KsbaContentType _KSBA_DEPRECATED;



typedef enum
  {
    KSBA_SR_NONE = 0,     /* Never seen by libksba user. */
    KSBA_SR_RUNNING = 1,  /* Never seen by libksba user. */
    KSBA_SR_GOT_CONTENT = 2,
    KSBA_SR_NEED_HASH = 3,
    KSBA_SR_BEGIN_DATA = 4,
    KSBA_SR_END_DATA = 5,
    KSBA_SR_READY = 6,
    KSBA_SR_NEED_SIG = 7,
    KSBA_SR_DETACHED_DATA = 8,
    KSBA_SR_BEGIN_ITEMS = 9,
    KSBA_SR_GOT_ITEM = 10,
    KSBA_SR_END_ITEMS = 11
  }
ksba_stop_reason_t;
typedef ksba_stop_reason_t KsbaStopReason _KSBA_DEPRECATED;

typedef enum
  {
    KSBA_CRLREASON_UNSPECIFIED = 1,
    KSBA_CRLREASON_KEY_COMPROMISE = 2,
    KSBA_CRLREASON_CA_COMPROMISE = 4,
    KSBA_CRLREASON_AFFILIATION_CHANGED = 8,
    KSBA_CRLREASON_SUPERSEDED = 16,
    KSBA_CRLREASON_CESSATION_OF_OPERATION = 32,
    KSBA_CRLREASON_CERTIFICATE_HOLD = 64,
    KSBA_CRLREASON_REMOVE_FROM_CRL = 256,
    KSBA_CRLREASON_PRIVILEGE_WITHDRAWN = 512,
    KSBA_CRLREASON_AA_COMPROMISE = 1024,
    KSBA_CRLREASON_OTHER = 32768
  }
ksba_crl_reason_t;
typedef ksba_crl_reason_t KsbaCRLReason _KSBA_DEPRECATED;

typedef enum
  {
    KSBA_OCSP_RSPSTATUS_SUCCESS = 0,
    KSBA_OCSP_RSPSTATUS_MALFORMED = 1,
    KSBA_OCSP_RSPSTATUS_INTERNAL = 2,
    KSBA_OCSP_RSPSTATUS_TRYLATER = 3,
    KSBA_OCSP_RSPSTATUS_SIGREQUIRED = 5,
    KSBA_OCSP_RSPSTATUS_UNAUTHORIZED = 6,
    KSBA_OCSP_RSPSTATUS_REPLAYED = 253,
    KSBA_OCSP_RSPSTATUS_OTHER = 254,
    KSBA_OCSP_RSPSTATUS_NONE = 255
  }
ksba_ocsp_response_status_t;

typedef enum
  {
    KSBA_STATUS_NONE = 0,
    KSBA_STATUS_UNKNOWN = 1,
    KSBA_STATUS_GOOD = 2,
    KSBA_STATUS_REVOKED = 4
  }
ksba_status_t;


typedef enum
  {
    KSBA_KEYUSAGE_DIGITAL_SIGNATURE =  1,
    KSBA_KEYUSAGE_NON_REPUDIATION   =  2,
    KSBA_KEYUSAGE_KEY_ENCIPHERMENT  =  4,
    KSBA_KEYUSAGE_DATA_ENCIPHERMENT =  8,
    KSBA_KEYUSAGE_KEY_AGREEMENT     = 16,
    KSBA_KEYUSAGE_KEY_CERT_SIGN     = 32,
    KSBA_KEYUSAGE_CRL_SIGN          = 64,
    KSBA_KEYUSAGE_ENCIPHER_ONLY    = 128,
    KSBA_KEYUSAGE_DECIPHER_ONLY    = 256
  }
ksba_key_usage_t;
typedef ksba_key_usage_t KsbaKeyUsage _KSBA_DEPRECATED;

/* ISO format, e.g. "19610711T172059", assumed to be UTC. */
typedef char ksba_isotime_t[16];


/* X.509 certificates are represented by this object.
   ksba_cert_new() creates such an object */
struct ksba_cert_s;
typedef struct ksba_cert_s *ksba_cert_t;
typedef struct ksba_cert_s *KsbaCert _KSBA_DEPRECATED;

/* CMS objects are controlled by this object.
   ksba_cms_new() creates it */
struct ksba_cms_s;
typedef struct ksba_cms_s *ksba_cms_t;
typedef struct ksba_cms_s *KsbaCMS _KSBA_DEPRECATED;

/* CRL objects are controlled by this object.
   ksba_crl_new() creates it */
struct ksba_crl_s;
typedef struct ksba_crl_s *ksba_crl_t;
typedef struct ksba_crl_s *KsbaCRL _KSBA_DEPRECATED;

/* OCSP objects are controlled by this object.
   ksba_ocsp_new() creates it. */
struct ksba_ocsp_s;
typedef struct ksba_ocsp_s *ksba_ocsp_t;

/* PKCS-10 creation is controlled by this object.
   ksba_certreq_new() creates it */
struct ksba_certreq_s;
typedef struct ksba_certreq_s *ksba_certreq_t;
typedef struct ksba_certreq_s *KsbaCertreq _KSBA_DEPRECATED;

/* This is a reader object for various purposes
   see ksba_reader_new et al. */
struct ksba_reader_s;
typedef struct ksba_reader_s *ksba_reader_t;
typedef struct ksba_reader_s *KsbaReader _KSBA_DEPRECATED;

/* This is a writer object for various purposes
   see ksba_writer_new et al. */
struct ksba_writer_s;
typedef struct ksba_writer_s *ksba_writer_t;
typedef struct ksba_writer_s *KsbaWriter _KSBA_DEPRECATED;

/* This is an object to store an ASN.1 parse tree as
   create by ksba_asn_parse_file() */
struct ksba_asn_tree_s;
typedef struct ksba_asn_tree_s *ksba_asn_tree_t;
typedef struct ksba_asn_tree_s *KsbaAsnTree _KSBA_DEPRECATED;

/* This is an object to reference a General Name.  Such an object is
   returned by several functions. */
struct ksba_name_s;
typedef struct ksba_name_s *ksba_name_t;
typedef struct ksba_name_s *KsbaName _KSBA_DEPRECATED;

/* KsbaSexp is just an unsigned char * which should be used for
   documentation purpose.  The S-expressions returned by libksba are
   always in canonical representation with an extra 0 byte at the end,
   so that one can print the values in the debugger and at least see
   the first bytes */
typedef unsigned char *ksba_sexp_t;
typedef unsigned char *KsbaSexp _KSBA_DEPRECATED;
typedef const unsigned char *ksba_const_sexp_t;
typedef const unsigned char *KsbaConstSexp _KSBA_DEPRECATED;


/*-- cert.c --*/
gpg_error_t ksba_cert_new (ksba_cert_t *acert);
void        ksba_cert_ref (ksba_cert_t cert);
void        ksba_cert_release (ksba_cert_t cert);
gpg_error_t ksba_cert_set_user_data (ksba_cert_t cert, const char *key,
                                     const void *data, size_t datalen);
gpg_error_t ksba_cert_get_user_data (ksba_cert_t cert, const char *key,
                                     void *buffer, size_t bufferlen,
                                     size_t *datalen);

gpg_error_t ksba_cert_read_der (ksba_cert_t cert, ksba_reader_t reader);
gpg_error_t ksba_cert_init_from_mem (ksba_cert_t cert,
                                     const void *buffer, size_t length);
const unsigned char *ksba_cert_get_image (ksba_cert_t cert, size_t *r_length);
gpg_error_t ksba_cert_hash (ksba_cert_t cert,
                            int what,
                            void (*hasher)(void *,
                                           const void *,
                                           size_t length),
                            void *hasher_arg);
const char *ksba_cert_get_digest_algo (ksba_cert_t cert);
ksba_sexp_t ksba_cert_get_serial (ksba_cert_t cert);
char       *ksba_cert_get_issuer (ksba_cert_t cert, int idx);
gpg_error_t ksba_cert_get_validity (ksba_cert_t cert, int what,
                                    ksba_isotime_t r_time);
char       *ksba_cert_get_subject (ksba_cert_t cert, int idx);
ksba_sexp_t ksba_cert_get_public_key (ksba_cert_t cert);
ksba_sexp_t ksba_cert_get_sig_val (ksba_cert_t cert);

gpg_error_t ksba_cert_get_extension (ksba_cert_t cert, int idx,
                                     char const **r_oid, int *r_crit,
                                     size_t *r_deroff, size_t *r_derlen);

gpg_error_t ksba_cert_is_ca (ksba_cert_t cert, int *r_ca, int *r_pathlen);
gpg_error_t ksba_cert_get_key_usage (ksba_cert_t cert, unsigned int *r_flags);
gpg_error_t ksba_cert_get_cert_policies (ksba_cert_t cert, char **r_policies);
gpg_error_t ksba_cert_get_ext_key_usages (ksba_cert_t cert, char **result);
gpg_error_t ksba_cert_get_crl_dist_point (ksba_cert_t cert, int idx,
                                          ksba_name_t *r_distpoint,
                                          ksba_name_t *r_issuer,
                                          ksba_crl_reason_t *r_reason);
gpg_error_t ksba_cert_get_auth_key_id (ksba_cert_t cert,
                                       ksba_sexp_t *r_keyid,
                                       ksba_name_t *r_name,
                                       ksba_sexp_t *r_serial);
gpg_error_t ksba_cert_get_subj_key_id (ksba_cert_t cert,
                                       int *r_crit,
                                       ksba_sexp_t *r_keyid);
gpg_error_t ksba_cert_get_authority_info_access (ksba_cert_t cert, int idx,
                                                 char **r_method,
                                                 ksba_name_t *r_location);
gpg_error_t ksba_cert_get_subject_info_access (ksba_cert_t cert, int idx,
                                               char **r_method,
                                               ksba_name_t *r_location);


/*-- cms.c --*/
ksba_content_type_t ksba_cms_identify (ksba_reader_t reader);

gpg_error_t ksba_cms_new (ksba_cms_t *r_cms);
void        ksba_cms_release (ksba_cms_t cms);
gpg_error_t ksba_cms_set_reader_writer (ksba_cms_t cms,
                                        ksba_reader_t r, ksba_writer_t w);

gpg_error_t ksba_cms_parse (ksba_cms_t cms, ksba_stop_reason_t *r_stopreason);
gpg_error_t ksba_cms_build (ksba_cms_t cms, ksba_stop_reason_t *r_stopreason);

ksba_content_type_t ksba_cms_get_content_type (ksba_cms_t cms, int what);
const char *ksba_cms_get_content_oid (ksba_cms_t cms, int what);
gpg_error_t ksba_cms_get_content_enc_iv (ksba_cms_t cms, void *iv,
                                         size_t maxivlen, size_t *ivlen);
const char *ksba_cms_get_digest_algo_list (ksba_cms_t cms, int idx);
gpg_error_t ksba_cms_get_issuer_serial (ksba_cms_t cms, int idx,
                                        char **r_issuer,
                                        ksba_sexp_t *r_serial);
const char *ksba_cms_get_digest_algo (ksba_cms_t cms, int idx);
ksba_cert_t ksba_cms_get_cert (ksba_cms_t cms, int idx);
gpg_error_t ksba_cms_get_message_digest (ksba_cms_t cms, int idx,
                                         char **r_digest, size_t *r_digest_len);
gpg_error_t ksba_cms_get_signing_time (ksba_cms_t cms, int idx,
                                       ksba_isotime_t r_sigtime);
gpg_error_t ksba_cms_get_sigattr_oids (ksba_cms_t cms, int idx,
                                       const char *reqoid, char **r_value);
ksba_sexp_t ksba_cms_get_sig_val (ksba_cms_t cms, int idx);
ksba_sexp_t ksba_cms_get_enc_val (ksba_cms_t cms, int idx);

void ksba_cms_set_hash_function (ksba_cms_t cms,
                                 void (*hash_fnc)(void *, const void *, size_t),
                                 void *hash_fnc_arg);

gpg_error_t ksba_cms_hash_signed_attrs (ksba_cms_t cms, int idx);


gpg_error_t ksba_cms_set_content_type (ksba_cms_t cms, int what,
                                       ksba_content_type_t type);
gpg_error_t ksba_cms_add_digest_algo (ksba_cms_t cms, const char *oid);
gpg_error_t ksba_cms_add_signer (ksba_cms_t cms, ksba_cert_t cert);
gpg_error_t ksba_cms_add_cert (ksba_cms_t cms, ksba_cert_t cert);
gpg_error_t ksba_cms_add_smime_capability (ksba_cms_t cms, const char *oid,
                                           const unsigned char *der,
                                           size_t derlen);
gpg_error_t ksba_cms_set_message_digest (ksba_cms_t cms, int idx,
                                         const unsigned char *digest,
                                         size_t digest_len);
gpg_error_t ksba_cms_set_signing_time (ksba_cms_t cms, int idx,
                                       const ksba_isotime_t sigtime);
gpg_error_t ksba_cms_set_sig_val (ksba_cms_t cms,
                                  int idx, ksba_const_sexp_t sigval);

gpg_error_t ksba_cms_set_content_enc_algo (ksba_cms_t cms,
                                           const char *oid,
                                           const void *iv,
                                           size_t ivlen);
gpg_error_t ksba_cms_add_recipient (ksba_cms_t cms, ksba_cert_t cert);
gpg_error_t ksba_cms_set_enc_val (ksba_cms_t cms,
                                  int idx, ksba_const_sexp_t encval);


/*-- crl.c --*/
gpg_error_t ksba_crl_new (ksba_crl_t *r_crl);
void        ksba_crl_release (ksba_crl_t crl);
gpg_error_t ksba_crl_set_reader (ksba_crl_t crl, ksba_reader_t r);
void        ksba_crl_set_hash_function (ksba_crl_t crl,
                                        void (*hash_fnc)(void *,
                                                         const void *, size_t),
                                        void *hash_fnc_arg);
const char *ksba_crl_get_digest_algo (ksba_crl_t crl);
gpg_error_t ksba_crl_get_issuer (ksba_crl_t crl, char **r_issuer);
gpg_error_t ksba_crl_get_extension (ksba_crl_t crl, int idx,
                                    char const **oid, int *critical,
                                    unsigned char const **der, size_t *derlen);
gpg_error_t ksba_crl_get_auth_key_id (ksba_crl_t crl,
                                      ksba_sexp_t *r_keyid,
                                      ksba_name_t *r_name,
                                      ksba_sexp_t *r_serial);
gpg_error_t ksba_crl_get_crl_number (ksba_crl_t crl, ksba_sexp_t *number);
gpg_error_t ksba_crl_get_update_times (ksba_crl_t crl,
                                       ksba_isotime_t this_update,
                                       ksba_isotime_t next_update);
gpg_error_t ksba_crl_get_item (ksba_crl_t crl,
                               ksba_sexp_t *r_serial,
                               ksba_isotime_t r_revocation_date,
                               ksba_crl_reason_t *r_reason);
ksba_sexp_t ksba_crl_get_sig_val (ksba_crl_t crl);
gpg_error_t ksba_crl_parse (ksba_crl_t crl, ksba_stop_reason_t *r_stopreason);



/*-- ocsp.c --*/
gpg_error_t ksba_ocsp_new (ksba_ocsp_t *r_oscp);
void ksba_ocsp_release (ksba_ocsp_t ocsp);
gpg_error_t ksba_ocsp_set_digest_algo (ksba_ocsp_t ocsp, const char *oid);
gpg_error_t ksba_ocsp_set_requestor (ksba_ocsp_t ocsp, ksba_cert_t cert);
gpg_error_t ksba_ocsp_add_target (ksba_ocsp_t ocsp,
                                  ksba_cert_t cert, ksba_cert_t issuer_cert);
size_t ksba_ocsp_set_nonce (ksba_ocsp_t ocsp,
                            unsigned char *nonce, size_t noncelen);

gpg_error_t ksba_ocsp_prepare_request (ksba_ocsp_t ocsp);
gpg_error_t ksba_ocsp_hash_request (ksba_ocsp_t ocsp,
                                    void (*hasher)(void *, const void *,
                                                   size_t length),
                                    void *hasher_arg);
gpg_error_t ksba_ocsp_set_sig_val (ksba_ocsp_t ocsp,
                                   ksba_const_sexp_t sigval);
gpg_error_t ksba_ocsp_add_cert (ksba_ocsp_t ocsp, ksba_cert_t cert);
gpg_error_t ksba_ocsp_build_request (ksba_ocsp_t ocsp,
                                     unsigned char **r_buffer,
                                     size_t *r_buflen);

gpg_error_t ksba_ocsp_parse_response (ksba_ocsp_t ocsp,
                                      const unsigned char *msg, size_t msglen,
                                      ksba_ocsp_response_status_t *resp_status);

const char *ksba_ocsp_get_digest_algo (ksba_ocsp_t ocsp);
gpg_error_t ksba_ocsp_hash_response (ksba_ocsp_t ocsp,
                                     const unsigned char *msg, size_t msglen,
                                     void (*hasher)(void *, const void *,
                                                    size_t length),
                                     void *hasher_arg);
ksba_sexp_t ksba_ocsp_get_sig_val (ksba_ocsp_t ocsp,
                                   ksba_isotime_t produced_at);
gpg_error_t ksba_ocsp_get_responder_id (ksba_ocsp_t ocsp,
                                        char **r_name,
                                        ksba_sexp_t *r_keyid);
ksba_cert_t ksba_ocsp_get_cert (ksba_ocsp_t ocsp, int idx);
gpg_error_t ksba_ocsp_get_status (ksba_ocsp_t ocsp, ksba_cert_t cert,
                                  ksba_status_t *r_status,
                                  ksba_isotime_t r_this_update,
                                  ksba_isotime_t r_next_update,
                                  ksba_isotime_t r_revocation_time,
                                  ksba_crl_reason_t *r_reason);
gpg_error_t ksba_ocsp_get_extension (ksba_ocsp_t ocsp, ksba_cert_t cert,
                                     int idx,
                                     char const **r_oid, int *r_crit,
                                     unsigned char const **r_der,
                                     size_t *r_derlen);


/*-- certreq.c --*/
gpg_error_t ksba_certreq_new (ksba_certreq_t *r_cr);
void        ksba_certreq_release (ksba_certreq_t cr);
gpg_error_t ksba_certreq_set_writer (ksba_certreq_t cr, ksba_writer_t w);
void         ksba_certreq_set_hash_function (
                               ksba_certreq_t cr,
                               void (*hash_fnc)(void *, const void *, size_t),
                               void *hash_fnc_arg);
gpg_error_t ksba_certreq_add_subject (ksba_certreq_t cr, const char *name);
gpg_error_t ksba_certreq_set_public_key (ksba_certreq_t cr,
                                         ksba_const_sexp_t key);
gpg_error_t ksba_certreq_add_extension (ksba_certreq_t cr,
                                        const char *oid, int is_crit,
                                        const void *der,
                                        size_t derlen);
gpg_error_t ksba_certreq_set_sig_val (ksba_certreq_t cr,
                                      ksba_const_sexp_t sigval);
gpg_error_t ksba_certreq_build (ksba_certreq_t cr,
                                ksba_stop_reason_t *r_stopreason);

/* The functions below are used to switch to X.509 certificate creation.  */
gpg_error_t ksba_certreq_set_serial (ksba_certreq_t cr, ksba_const_sexp_t sn);
gpg_error_t ksba_certreq_set_issuer (ksba_certreq_t cr, const char *name);
gpg_error_t ksba_certreq_set_validity (ksba_certreq_t cr, int what,
                                       const ksba_isotime_t timebuf);
gpg_error_t ksba_certreq_set_siginfo (ksba_certreq_t cr,
                                      ksba_const_sexp_t siginfo);



/*-- reader.c --*/
gpg_error_t ksba_reader_new (ksba_reader_t *r_r);
void        ksba_reader_release (ksba_reader_t r);
gpg_error_t ksba_reader_set_release_notify (ksba_reader_t r,
                                            void (*notify)(void*,ksba_reader_t),
                                            void *notify_value);
gpg_error_t ksba_reader_clear (ksba_reader_t r,
                               unsigned char **buffer, size_t *buflen);
gpg_error_t ksba_reader_error (ksba_reader_t r);

gpg_error_t ksba_reader_set_mem (ksba_reader_t r,
                               const void *buffer, size_t length);
gpg_error_t ksba_reader_set_fd (ksba_reader_t r, int fd);
gpg_error_t ksba_reader_set_file (ksba_reader_t r, FILE *fp);
gpg_error_t ksba_reader_set_cb (ksba_reader_t r,
                              int (*cb)(void*,char *,size_t,size_t*),
                              void *cb_value );

gpg_error_t ksba_reader_read (ksba_reader_t r,
                            char *buffer, size_t length, size_t *nread);
gpg_error_t ksba_reader_unread (ksba_reader_t r, const void *buffer, size_t count);
unsigned long ksba_reader_tell (ksba_reader_t r);

/*-- writer.c --*/
gpg_error_t ksba_writer_new (ksba_writer_t *r_w);
void        ksba_writer_release (ksba_writer_t w);
gpg_error_t ksba_writer_set_release_notify (ksba_writer_t w,
                                            void (*notify)(void*,ksba_writer_t),
                                            void *notify_value);
int         ksba_writer_error (ksba_writer_t w);
unsigned long ksba_writer_tell (ksba_writer_t w);
gpg_error_t ksba_writer_set_fd (ksba_writer_t w, int fd);
gpg_error_t ksba_writer_set_file (ksba_writer_t w, FILE *fp);
gpg_error_t ksba_writer_set_cb (ksba_writer_t w,
                                int (*cb)(void*,const void *,size_t),
                                void *cb_value);
gpg_error_t ksba_writer_set_mem (ksba_writer_t w, size_t initial_size);
const void *ksba_writer_get_mem (ksba_writer_t w, size_t *nbytes);
void *      ksba_writer_snatch_mem (ksba_writer_t w, size_t *nbytes);
gpg_error_t ksba_writer_set_filter (ksba_writer_t w,
                                    gpg_error_t (*filter)(void*,
                                             const void *,size_t, size_t *,
                                             void *, size_t, size_t *),
                                    void *filter_arg);

gpg_error_t ksba_writer_write (ksba_writer_t w, const void *buffer, size_t length);
gpg_error_t ksba_writer_write_octet_string (ksba_writer_t w,
                                          const void *buffer, size_t length,
                                          int flush);

/*-- asn1-parse.y --*/
int ksba_asn_parse_file (const char *filename, ksba_asn_tree_t *result,
                         int debug);
void ksba_asn_tree_release (ksba_asn_tree_t tree);

/*-- asn1-func.c --*/
void ksba_asn_tree_dump (ksba_asn_tree_t tree, const char *name, FILE *fp);
gpg_error_t ksba_asn_create_tree (const char *mod_name, ksba_asn_tree_t *result);

/*-- oid.c --*/
char *ksba_oid_to_str (const char *buffer, size_t length);
gpg_error_t ksba_oid_from_str (const char *string,
                               unsigned char **rbuf, size_t *rlength);

/*-- dn.c --*/
gpg_error_t ksba_dn_der2str (const void *der, size_t derlen, char **r_string);
gpg_error_t ksba_dn_str2der (const char *string,
                             unsigned char **rder, size_t *rderlen);
gpg_error_t ksba_dn_teststr (const char *string, int seq,
                             size_t *rerroff, size_t *rerrlen);


/*-- name.c --*/
gpg_error_t ksba_name_new (ksba_name_t *r_name);
void        ksba_name_ref (ksba_name_t name);
void        ksba_name_release (ksba_name_t name);
const char *ksba_name_enum (ksba_name_t name, int idx);
char       *ksba_name_get_uri (ksba_name_t name, int idx);


/*-- util.c --*/
void ksba_set_malloc_hooks ( void *(*new_alloc_func)(size_t n),
                             void *(*new_realloc_func)(void *p, size_t n),
                             void (*new_free_func)(void*) );
void ksba_set_hash_buffer_function ( gpg_error_t (*fnc)
                                     (void *arg, const char *oid,
                                      const void *buffer, size_t length,
                                      size_t resultsize,
                                      unsigned char *result,
                                      size_t *resultlen),
                                     void *fnc_arg);
void *ksba_malloc (size_t n );
void *ksba_calloc (size_t n, size_t m );
void *ksba_realloc (void *p, size_t n);
char *ksba_strdup (const char *p);
void  ksba_free ( void *a );

/*--version.c --*/
const char *ksba_check_version (const char *req_version);

#ifdef __cplusplus
}
#endif
#endif /*KSBA_H*/
