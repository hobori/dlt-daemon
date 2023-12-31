/*
 * SPDX license identifier: MPL-2.0
 *
 * Copyright (C) 2011-2015, BMW AG
 *
 * This file is part of COVESA Project DLT - Diagnostic Log and Trace.
 *
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License (MPL), v. 2.0.
 * If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * For further information see http://www.covesa.org/.
 */

/*!
 * \author Alexander Wenzel <alexander.aw.wenzel@bmw.de>
 *
 * \copyright Copyright © 2011-2015 BMW AG. \n
 * License MPL-2.0: Mozilla Public License version 2.0 http://mozilla.org/MPL/2.0/.
 *
 * \file dlt_protocol.h
 */


/*******************************************************************************
**                                                                            **
**  SRC-MODULE: dlt_protocol.h                                                **
**                                                                            **
**  TARGET    : linux                                                         **
**                                                                            **
**  PROJECT   : DLT                                                           **
**                                                                            **
**  AUTHOR    : Alexander Wenzel Alexander.AW.Wenzel@bmw.de                   **
**              Markus Klein                                                  **
**                                                                            **
**  PURPOSE   :                                                               **
**                                                                            **
**  REMARKS   :                                                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
**  aw          Alexander Wenzel           BMW                                **
**  mk          Markus Klein               Fraunhofer ESK                     **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * $LastChangedRevision$
 * $LastChangedDate$
 * $LastChangedBy$
 * Initials    Date         Comment
 * aw          13.01.2010   initial
 */
#ifndef DLT_PROTOCOL_H
#define DLT_PROTOCOL_H

/**
 * \defgroup protocolapi DLT Protocol API
 * \addtogroup protocolapi
 \{
 */

/*
 * Definitions of the htyp parameter in standard header.
 */
#define DLT_HTYP_UEH  0x01 /**< use extended header */
#define DLT_HTYP_MSBF 0x02 /**< MSB first */
#define DLT_HTYP_WEID 0x04 /**< with ECU ID */
#define DLT_HTYP_WSID 0x08 /**< with session ID */
#define DLT_HTYP_WTMS 0x10 /**< with timestamp */
#define DLT_HTYP_VERS 0xe0 /**< version number, 0x1 */

#define DLT_IS_HTYP_UEH(htyp)  ((htyp) & DLT_HTYP_UEH)
#define DLT_IS_HTYP_MSBF(htyp) ((htyp) & DLT_HTYP_MSBF)
#define DLT_IS_HTYP_WEID(htyp) ((htyp) & DLT_HTYP_WEID)
#define DLT_IS_HTYP_WSID(htyp) ((htyp) & DLT_HTYP_WSID)
#define DLT_IS_HTYP_WTMS(htyp) ((htyp) & DLT_HTYP_WTMS)

#define DLT_HTYP_PROTOCOL_VERSION1 (1 << 5)

/*
 * Definitions of msin parameter in extended header.
 */
#define DLT_MSIN_VERB 0x01 /**< verbose */
#define DLT_MSIN_MSTP 0x0e /**< message type */
#define DLT_MSIN_MTIN 0xf0 /**< message type info */

#define DLT_MSIN_MSTP_SHIFT 1 /**< shift right offset to get mstp value */
#define DLT_MSIN_MTIN_SHIFT 4 /**< shift right offset to get mtin value */

#define DLT_IS_MSIN_VERB(msin)   ((msin) & DLT_MSIN_VERB)
#define DLT_GET_MSIN_MSTP(msin) (((msin) & DLT_MSIN_MSTP) >> DLT_MSIN_MSTP_SHIFT)
#define DLT_GET_MSIN_MTIN(msin) (((msin) & DLT_MSIN_MTIN) >> DLT_MSIN_MTIN_SHIFT)

/*
 * Definitions of mstp parameter in extended header.
 */
#define DLT_TYPE_LOG       0x00 /**< Log message type */
#define DLT_TYPE_APP_TRACE 0x01 /**< Application trace message type */
#define DLT_TYPE_NW_TRACE  0x02 /**< Network trace message type */
#define DLT_TYPE_CONTROL   0x03 /**< Control message type */

/*
 * Definitions of msti parameter in extended header.
 */
#define DLT_TRACE_VARIABLE     0x01 /**< tracing of a variable */
#define DLT_TRACE_FUNCTION_IN  0x02 /**< tracing of function calls */
#define DLT_TRACE_FUNCTION_OUT 0x03 /**< tracing of function return values */
#define DLT_TRACE_STATE        0x04 /**< tracing of states of a state machine */
#define DLT_TRACE_VFB          0x05 /**< tracing of virtual function bus */

/*
 * Definitions of msbi parameter in extended header.
 */

/* see file dlt_user.h */

/*
 * Definitions of msci parameter in extended header.
 */
#define DLT_CONTROL_REQUEST    0x01 /**< Request message */
#define DLT_CONTROL_RESPONSE   0x02 /**< Response to request message */
#define DLT_CONTROL_TIME       0x03 /**< keep-alive message */

#define DLT_MSIN_CONTROL_REQUEST  ((DLT_TYPE_CONTROL << DLT_MSIN_MSTP_SHIFT) | \
                                   (DLT_CONTROL_REQUEST << DLT_MSIN_MTIN_SHIFT))
#define DLT_MSIN_CONTROL_RESPONSE ((DLT_TYPE_CONTROL << DLT_MSIN_MSTP_SHIFT) | \
                                   (DLT_CONTROL_RESPONSE << DLT_MSIN_MTIN_SHIFT))
#define DLT_MSIN_CONTROL_TIME     ((DLT_TYPE_CONTROL << DLT_MSIN_MSTP_SHIFT) | \
                                   (DLT_CONTROL_TIME << DLT_MSIN_MTIN_SHIFT))

/*
 * Definitions of types of arguments in payload.
 */
#define DLT_TYPE_INFO_TYLE 0x0000000f /**< Length of standard data: 1 = 8bit, 2 = 16bit, 3 = 32 bit, 4 = 64 bit, 5 = 128 bit */
#define DLT_TYPE_INFO_BOOL 0x00000010 /**< Boolean data */
#define DLT_TYPE_INFO_SINT 0x00000020 /**< Signed integer data */
#define DLT_TYPE_INFO_UINT 0x00000040 /**< Unsigned integer data */
#define DLT_TYPE_INFO_FLOA 0x00000080 /**< Float data */
#define DLT_TYPE_INFO_ARAY 0x00000100 /**< Array of standard types */
#define DLT_TYPE_INFO_STRG 0x00000200 /**< String */
#define DLT_TYPE_INFO_RAWD 0x00000400 /**< Raw data */
#define DLT_TYPE_INFO_VARI 0x00000800 /**< Set, if additional information to a variable is available */
#define DLT_TYPE_INFO_FIXP 0x00001000 /**< Set, if quantization and offset are added */
#define DLT_TYPE_INFO_TRAI 0x00002000 /**< Set, if additional trace information is added */
#define DLT_TYPE_INFO_STRU 0x00004000 /**< Struct */
#define DLT_TYPE_INFO_SCOD 0x00038000 /**< coding of the type string: 0 = ASCII, 1 = UTF-8 */

#define DLT_TYLE_8BIT      0x00000001
#define DLT_TYLE_16BIT     0x00000002
#define DLT_TYLE_32BIT     0x00000003
#define DLT_TYLE_64BIT     0x00000004
#define DLT_TYLE_128BIT    0x00000005

#define DLT_SCOD_ASCII      0x00000000
#define DLT_SCOD_UTF8       0x00008000
#define DLT_SCOD_HEX        0x00010000
#define DLT_SCOD_BIN        0x00018000

/*
 * Definitions of DLT services.
 */
#define DLT_SERVICE_ID_CALLSW_CINJECTION 0xFFF

enum dlt_services {
    DLT_SERVICE_ID = 0x00,
    DLT_SERVICE_ID_SET_LOG_LEVEL = 0x01,
    DLT_SERVICE_ID_SET_TRACE_STATUS = 0x02,
    DLT_SERVICE_ID_GET_LOG_INFO = 0x03,
    DLT_SERVICE_ID_GET_DEFAULT_LOG_LEVEL = 0x04,
    DLT_SERVICE_ID_STORE_CONFIG = 0x05,
    DLT_SERVICE_ID_RESET_TO_FACTORY_DEFAULT = 0x06,
    DLT_SERVICE_ID_SET_COM_INTERFACE_STATUS = 0x07,
    DLT_SERVICE_ID_SET_COM_INTERFACE_MAX_BANDWIDTH = 0x08,
    DLT_SERVICE_ID_SET_VERBOSE_MODE = 0x09,
    DLT_SERVICE_ID_SET_MESSAGE_FILTERING = 0x0A,
    DLT_SERVICE_ID_SET_TIMING_PACKETS = 0x0B,
    DLT_SERVICE_ID_GET_LOCAL_TIME = 0x0C,
    DLT_SERVICE_ID_USE_ECU_ID = 0x0D,
    DLT_SERVICE_ID_USE_SESSION_ID = 0x0E,
    DLT_SERVICE_ID_USE_TIMESTAMP = 0x0F,
    DLT_SERVICE_ID_USE_EXTENDED_HEADER = 0x10,
    DLT_SERVICE_ID_SET_DEFAULT_LOG_LEVEL = 0x11,
    DLT_SERVICE_ID_SET_DEFAULT_TRACE_STATUS = 0x12,
    DLT_SERVICE_ID_GET_SOFTWARE_VERSION = 0x13,
    DLT_SERVICE_ID_MESSAGE_BUFFER_OVERFLOW = 0x14,
    DLT_SERVICE_ID_LAST_ENTRY
};

enum dlt_user_services {
    DLT_USER_SERVICE_ID = 0xF00,
    DLT_SERVICE_ID_UNREGISTER_CONTEXT = 0xF01,
    DLT_SERVICE_ID_CONNECTION_INFO = 0xF02,
    DLT_SERVICE_ID_TIMEZONE = 0xF03,
    DLT_SERVICE_ID_MARKER = 0xF04,
    DLT_SERVICE_ID_OFFLINE_LOGSTORAGE = 0xF05,
    DLT_SERVICE_ID_PASSIVE_NODE_CONNECT = 0xF06,
    DLT_SERVICE_ID_PASSIVE_NODE_CONNECTION_STATUS = 0xF07,
    DLT_SERVICE_ID_SET_ALL_LOG_LEVEL = 0xF08,
    DLT_SERVICE_ID_SET_ALL_TRACE_STATUS = 0xF09,
    DLT_SERVICE_ID_RESERVED_B = 0xF0B,
    DLT_SERVICE_ID_RESERVED_C = 0xF0C,
    DLT_SERVICE_ID_RESERVED_D = 0xF0D,
    DLT_SERVICE_ID_RESERVED_E = 0xF0E,
    DLT_USER_SERVICE_ID_LAST_ENTRY
};

/* Need to be adapted if another service is added */
extern const char *const dlt_service_names[];
extern const char *const dlt_user_service_names[];

extern const char *dlt_get_service_name(unsigned int id);

/*
 * Definitions of DLT service response status
 */
#define DLT_SERVICE_RESPONSE_OK            0x00 /**< Control message response: OK */
#define DLT_SERVICE_RESPONSE_NOT_SUPPORTED 0x01 /**< Control message response: Not supported */
#define DLT_SERVICE_RESPONSE_ERROR         0x02 /**< Control message response: Error */
#define DLT_SERVICE_RESPONSE_PERM_DENIED   0x03 /**< Control message response: Permission denied */
#define DLT_SERVICE_RESPONSE_WARNING       0x04 /**< Control message response: warning */
#define DLT_SERVICE_RESPONSE_LAST          0x05 /**< Used as max value */

/*
 * Definitions of DLT service connection state
 */
#define DLT_CONNECTION_STATUS_DISCONNECTED 0x01 /**< Client is disconnected */
#define DLT_CONNECTION_STATUS_CONNECTED    0x02 /**< Client is connected */

/*
 * Definitions of DLT GET_LOG_INFO status
 */
#define GET_LOG_INFO_STATUS_MIN 3
#define GET_LOG_INFO_STATUS_MAX 7
#define GET_LOG_INFO_STATUS_NO_MATCHING_CTX 8
#define GET_LOG_INFO_STATUS_RESP_DATA_OVERFLOW 9


/**
 \}
 */

#endif /* DLT_PROTOCOL_H */
