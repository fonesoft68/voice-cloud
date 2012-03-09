// Reminder: Modify typemap.dat to customize the header file generated by wsdl2h
/* addclient.h
   Generated by wsdl2h 2.8.3 from Client_1.wsdl Client_2.wsdl Client_3.wsdl and typemap.dat
   2012-03-02 00:35:17 GMT

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS
   USE THE soapcpp2-GENERATED SOURCE CODE FILES FOR YOUR PROJECT BUILDS

   gSOAP XML Web services tools.
   Copyright (C) 2001-2010 Robert van Engelen, Genivia Inc. All Rights Reserved.
   Part of this software is released under one of the following licenses:
   GPL or Genivia's license for commercial use.
*/

/** @page page_notes Usage Notes

NOTE:

 - Run soapcpp2 on addclient.h to generate the SOAP/XML processing logic.
   Use soapcpp2 option -I to specify paths for #import
   To build with STL, 'stlvector.h' is imported from 'import' dir in package.
   Use soapcpp2 option -i to generate improved proxy and server classes.
 - Use wsdl2h options -c and -s to generate pure C code or C++ code without STL.
 - Use 'typemap.dat' to control namespace bindings and type mappings.
   It is strongly recommended to customize the names of the namespace prefixes
   generated by wsdl2h. To do so, modify the prefix bindings in the Namespaces
   section below and add the modified lines to 'typemap.dat' to rerun wsdl2h.
 - Use Doxygen (www.doxygen.org) on this file to generate documentation.
 - Use wsdl2h options -nname and -Nname to globally rename the prefix 'ns'.
 - Use wsdl2h option -d to enable DOM support for xsd:anyType.
 - Use wsdl2h option -g to auto-generate readers and writers for root elements.
 - Struct/class members serialized as XML attributes are annotated with a '@'.
 - Struct/class members that have a special role are annotated with a '$'.

WARNING:

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS.
   USE THE SOURCE CODE FILES GENERATED BY soapcpp2 FOR YOUR PROJECT BUILDS:
   THE soapStub.h FILE CONTAINS THIS CONTENT WITHOUT ANNOTATIONS.

LICENSE:

@verbatim
--------------------------------------------------------------------------------
gSOAP XML Web services tools
Copyright (C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.

This software is released under one of the following two licenses:
1) GPL or 2) Genivia's license for commercial use.
--------------------------------------------------------------------------------
1) GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
2) A commercial-use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
@endverbatim

*/


//gsoapopt cw

/******************************************************************************\
 *                                                                            *
 * Definitions                                                                *
 *                                                                            *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Import                                                                     *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Namespaces                                                          *
 *                                                                            *
\******************************************************************************/


/* NOTE:

It is strongly recommended to customize the names of the namespace prefixes
generated by wsdl2h. To do so, modify the prefix bindings below and add the
modified lines to typemap.dat to rerun wsdl2h:

ns1 = "urn:Client_1"
ns2 = "urn:Client_2"
ns3 = "urn:Client_3"

*/

#define SOAP_NAMESPACE_OF_ns1	"urn:Client_1"
//gsoap ns1   schema namespace:	urn:Client_1
//gsoap ns1   schema form:	unqualified

#define SOAP_NAMESPACE_OF_ns2	"urn:Client_2"
//gsoap ns2   schema namespace:	urn:Client_2
//gsoap ns2   schema form:	unqualified

#define SOAP_NAMESPACE_OF_ns3	"urn:Client_3"
//gsoap ns3   schema namespace:	urn:Client_3
//gsoap ns3   schema form:	unqualified

/******************************************************************************\
 *                                                                            *
 * Built-in Schema Types and Top-Level Elements and Attributes                *
 *                                                                            *
\******************************************************************************/


/// Primitive built-in type "xs:anyURI"
typedef char* xsd__anyURI;

/// Built-in type "xs:base64Binary".
struct xsd__base64Binary
{	unsigned char *__ptr;
	int __size;
	char *id, *type, *options; // NOTE: for DIME and MTOM XOP attachments only
};


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   urn:Client_1                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   urn:Client_2                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   urn:Client_3                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   urn:Client_2                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   urn:Client_3                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   urn:Client_1                                                             *
 *                                                                            *
\******************************************************************************/


/// "urn:Client_1":soap-string is a complexType.
struct ns1__soap_string
{
/// Element size of type xs:int.
    int                                  size                           1;	///< Required element.
/// Element str of type xs:string.
    char*                                str                            0;	///< Nullable pointer.
};

/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   urn:Client_2                                                             *
 *                                                                            *
\******************************************************************************/


/// "urn:Client_2":soap-string is a complexType.
struct ns2__soap_string
{
/// Element size of type xs:int.
    int                                  size                           1;	///< Required element.
/// Element str of type xs:string.
    char*                                str                            0;	///< Nullable pointer.
};

/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   urn:Client_3                                                             *
 *                                                                            *
\******************************************************************************/


/// "urn:Client_3":soap-string is a complexType.
struct ns3__soap_string
{
/// Element size of type xs:int.
    int                                  size                           1;	///< Required element.
/// Element str of type xs:string.
    char*                                str                            0;	///< Nullable pointer.
};

/// "urn:Client_1":data is a complexType with simpleContent.
struct ns1__data
{
/// __item wraps 'xs:base64Binary' simpleContent.
    struct xsd__base64Binary             __item                        ;
/// Attribute href of type xs:anyURI.
   @xsd__anyURI                          href                           0;	///< Optional attribute.
};

/// "urn:Client_2":data is a complexType with simpleContent.
struct ns2__data
{
/// __item wraps 'xs:base64Binary' simpleContent.
    struct xsd__base64Binary             __item                        ;
/// Attribute href of type xs:anyURI.
   @xsd__anyURI                          href                           0;	///< Optional attribute.
};

/// "urn:Client_3":data is a complexType with simpleContent.
struct ns3__data
{
/// __item wraps 'xs:base64Binary' simpleContent.
    struct xsd__base64Binary             __item                        ;
/// Attribute href of type xs:anyURI.
   @xsd__anyURI                          href                           0;	///< Optional attribute.
};

/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   urn:Client_1                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   urn:Client_1                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   urn:Client_2                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   urn:Client_2                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   urn:Client_3                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   urn:Client_3                                                             *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Services                                                                   *
 *                                                                            *
\******************************************************************************/


//gsoap ns1  service name:	Client_USCORE1 
//gsoap ns1  service type:	Client_USCORE1PortType 
//gsoap ns1  service port:	http://10.42.43.41:8080/ 
//gsoap ns1  service namespace:	urn:Client_1 
//gsoap ns1  service transport:	http://schemas.xmlsoap.org/soap/http 

//gsoap ns2  service name:	Client_USCORE2 
//gsoap ns2  service type:	Client_USCORE2PortType 
//gsoap ns2  service port:	http://10.42.43.42:8080/ 
//gsoap ns2  service namespace:	urn:Client_2 
//gsoap ns2  service transport:	http://schemas.xmlsoap.org/soap/http 

//gsoap ns3  service name:	Client_USCORE3 
//gsoap ns3  service type:	Client_USCORE3PortType 
//gsoap ns3  service port:	http://59.66.185.77:8080/ 
//gsoap ns3  service namespace:	urn:Client_3 
//gsoap ns3  service transport:	http://schemas.xmlsoap.org/soap/http 

/** @mainpage Service Definitions

@section Service_bindings Service Bindings

  - @ref Client_USCORE1

  - @ref Client_USCORE2

  - @ref Client_USCORE3

@section Service_more More Information

  - @ref page_notes "Usage Notes"

  - @ref page_XMLDataBinding "XML Data Binding"

  - @ref SOAP_ENV__Header "SOAP Header Content" (when applicable)

  - @ref SOAP_ENV__Detail "SOAP Fault Detail Content" (when applicable)


*/

/**

@page Client_USCORE1 Binding "Client_USCORE1"

@section Client_USCORE1_service Service Documentation "Client_1"
gSOAP 2.8.5 generated service definition

@section Client_USCORE1_operations Operations of Binding  "Client_USCORE1"

  - @ref ns1__ReceiveTaskList

  - @ref ns1__TaskSolve

  - @ref ns1__isBusy

@section Client_USCORE1_ports Endpoints of Binding  "Client_USCORE1"

  - http://10.42.43.41:8080/

Note: use wsdl2h option -N to change the service binding prefix name

*/

/**

@page Client_USCORE2 Binding "Client_USCORE2"

@section Client_USCORE2_service Service Documentation "Client_2"
gSOAP 2.8.5 generated service definition

@section Client_USCORE2_operations Operations of Binding  "Client_USCORE2"

  - @ref ns2__ReceiveTaskList

  - @ref ns2__TaskSolve

  - @ref ns2__isBusy

@section Client_USCORE2_ports Endpoints of Binding  "Client_USCORE2"

  - http://10.42.43.42:8080/

Note: use wsdl2h option -N to change the service binding prefix name

*/

/**

@page Client_USCORE3 Binding "Client_USCORE3"

@section Client_USCORE3_service Service Documentation "Client_3"
gSOAP 2.8.5 generated service definition

@section Client_USCORE3_operations Operations of Binding  "Client_USCORE3"

  - @ref ns3__ReceiveTaskList

  - @ref ns3__TaskSolve

  - @ref ns3__isBusy

@section Client_USCORE3_ports Endpoints of Binding  "Client_USCORE3"

  - http://59.66.185.77:8080/

Note: use wsdl2h option -N to change the service binding prefix name

*/

/******************************************************************************\
 *                                                                            *
 * Service Binding                                                            *
 *   Client_USCORE1                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__ReceiveTaskList                                                     *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__ReceiveTaskListResponse" of service binding "Client_USCORE1" operation "ns1__ReceiveTaskList"
struct ns1__ReceiveTaskListResponse
{
    struct ns1__soap_string*            rest;
};

/// Operation "ns1__ReceiveTaskList" of service binding "Client_USCORE1"

/**

Operation details:

Service definition of function ns__ReceiveTaskList

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__ReceiveTaskList(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    struct ns1__data*                   data,
    // response parameters:
    struct ns1__ReceiveTaskListResponse*
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__ReceiveTaskList(
    struct soap *soap,
    // request parameters:
    struct ns1__data*                   data,
    // response parameters:
    struct ns1__ReceiveTaskListResponse*
  );
@endcode

*/

//gsoap ns1  service method-style:	ReceiveTaskList rpc
//gsoap ns1  service method-encoding:	ReceiveTaskList http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	ReceiveTaskList ""
int ns1__ReceiveTaskList(
    struct ns1__data*                   data,	///< Request parameter
    struct ns1__ReceiveTaskListResponse*	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__TaskSolve                                                           *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__TaskSolveResponse" of service binding "Client_USCORE1" operation "ns1__TaskSolve"
struct ns1__TaskSolveResponse
{
    struct ns1__soap_string*            ret;
};

/// Operation "ns1__TaskSolve" of service binding "Client_USCORE1"

/**

Operation details:

Service definition of function ns__TaskSolve

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__TaskSolve(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    int                                 taskId,
    struct ns1__soap_string*            task,
    // response parameters:
    struct ns1__TaskSolveResponse*
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__TaskSolve(
    struct soap *soap,
    // request parameters:
    int                                 taskId,
    struct ns1__soap_string*            task,
    // response parameters:
    struct ns1__TaskSolveResponse*
  );
@endcode

*/

//gsoap ns1  service method-style:	TaskSolve rpc
//gsoap ns1  service method-encoding:	TaskSolve http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	TaskSolve ""
int ns1__TaskSolve(
    int                                 taskId,	///< Request parameter
    struct ns1__soap_string*            task,	///< Request parameter
    struct ns1__TaskSolveResponse      *	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__isBusy                                                              *
 *                                                                            *
\******************************************************************************/


/// Operation "ns1__isBusy" of service binding "Client_USCORE1"

/**

Operation details:

Service definition of function ns__isBusy

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__isBusy(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    // response parameters:
    int                                *flag
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__isBusy(
    struct soap *soap,
    // request parameters:
    // response parameters:
    int                                *flag
  );
@endcode

*/

//gsoap ns1  service method-style:	isBusy rpc
//gsoap ns1  service method-encoding:	isBusy http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns1  service method-action:	isBusy ""
int ns1__isBusy(
    int                                *flag	///< Response parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Binding                                                            *
 *   Client_USCORE2                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns2__ReceiveTaskList                                                     *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns2__ReceiveTaskListResponse" of service binding "Client_USCORE2" operation "ns2__ReceiveTaskList"
struct ns2__ReceiveTaskListResponse
{
    struct ns2__soap_string*            rest;
};

/// Operation "ns2__ReceiveTaskList" of service binding "Client_USCORE2"

/**

Operation details:

Service definition of function ns__ReceiveTaskList

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns2__ReceiveTaskList(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    struct ns2__data*                   data,
    // response parameters:
    struct ns2__ReceiveTaskListResponse*
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns2__ReceiveTaskList(
    struct soap *soap,
    // request parameters:
    struct ns2__data*                   data,
    // response parameters:
    struct ns2__ReceiveTaskListResponse*
  );
@endcode

*/

//gsoap ns2  service method-style:	ReceiveTaskList rpc
//gsoap ns2  service method-encoding:	ReceiveTaskList http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns2  service method-action:	ReceiveTaskList ""
int ns2__ReceiveTaskList(
    struct ns2__data*                   data,	///< Request parameter
    struct ns2__ReceiveTaskListResponse*	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns2__TaskSolve                                                           *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns2__TaskSolveResponse" of service binding "Client_USCORE2" operation "ns2__TaskSolve"
struct ns2__TaskSolveResponse
{
    struct ns2__soap_string*            ret;
};

/// Operation "ns2__TaskSolve" of service binding "Client_USCORE2"

/**

Operation details:

Service definition of function ns__TaskSolve

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns2__TaskSolve(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    int                                 taskId,
    struct ns2__soap_string*            task,
    // response parameters:
    struct ns2__TaskSolveResponse*
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns2__TaskSolve(
    struct soap *soap,
    // request parameters:
    int                                 taskId,
    struct ns2__soap_string*            task,
    // response parameters:
    struct ns2__TaskSolveResponse*
  );
@endcode

*/

//gsoap ns2  service method-style:	TaskSolve rpc
//gsoap ns2  service method-encoding:	TaskSolve http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns2  service method-action:	TaskSolve ""
int ns2__TaskSolve(
    int                                 taskId,	///< Request parameter
    struct ns2__soap_string*            task,	///< Request parameter
    struct ns2__TaskSolveResponse      *	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns2__isBusy                                                              *
 *                                                                            *
\******************************************************************************/


/// Operation "ns2__isBusy" of service binding "Client_USCORE2"

/**

Operation details:

Service definition of function ns__isBusy

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns2__isBusy(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    // response parameters:
    int                                *flag
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns2__isBusy(
    struct soap *soap,
    // request parameters:
    // response parameters:
    int                                *flag
  );
@endcode

*/

//gsoap ns2  service method-style:	isBusy rpc
//gsoap ns2  service method-encoding:	isBusy http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns2  service method-action:	isBusy ""
int ns2__isBusy(
    int                                *flag	///< Response parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Binding                                                            *
 *   Client_USCORE3                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns3__ReceiveTaskList                                                     *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns3__ReceiveTaskListResponse" of service binding "Client_USCORE3" operation "ns3__ReceiveTaskList"
struct ns3__ReceiveTaskListResponse
{
    struct ns3__soap_string*            rest;
};

/// Operation "ns3__ReceiveTaskList" of service binding "Client_USCORE3"

/**

Operation details:

Service definition of function ns__ReceiveTaskList

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns3__ReceiveTaskList(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    struct ns3__data*                   data,
    // response parameters:
    struct ns3__ReceiveTaskListResponse*
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns3__ReceiveTaskList(
    struct soap *soap,
    // request parameters:
    struct ns3__data*                   data,
    // response parameters:
    struct ns3__ReceiveTaskListResponse*
  );
@endcode

*/

//gsoap ns3  service method-style:	ReceiveTaskList rpc
//gsoap ns3  service method-encoding:	ReceiveTaskList http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns3  service method-action:	ReceiveTaskList ""
int ns3__ReceiveTaskList(
    struct ns3__data*                   data,	///< Request parameter
    struct ns3__ReceiveTaskListResponse*	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns3__TaskSolve                                                           *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns3__TaskSolveResponse" of service binding "Client_USCORE3" operation "ns3__TaskSolve"
struct ns3__TaskSolveResponse
{
    struct ns3__soap_string*            ret;
};

/// Operation "ns3__TaskSolve" of service binding "Client_USCORE3"

/**

Operation details:

Service definition of function ns__TaskSolve

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns3__TaskSolve(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    int                                 taskId,
    struct ns3__soap_string*            task,
    // response parameters:
    struct ns3__TaskSolveResponse*
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns3__TaskSolve(
    struct soap *soap,
    // request parameters:
    int                                 taskId,
    struct ns3__soap_string*            task,
    // response parameters:
    struct ns3__TaskSolveResponse*
  );
@endcode

*/

//gsoap ns3  service method-style:	TaskSolve rpc
//gsoap ns3  service method-encoding:	TaskSolve http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns3  service method-action:	TaskSolve ""
int ns3__TaskSolve(
    int                                 taskId,	///< Request parameter
    struct ns3__soap_string*            task,	///< Request parameter
    struct ns3__TaskSolveResponse      *	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns3__isBusy                                                              *
 *                                                                            *
\******************************************************************************/


/// Operation "ns3__isBusy" of service binding "Client_USCORE3"

/**

Operation details:

Service definition of function ns__isBusy

  - SOAP RPC encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns3__isBusy(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    // response parameters:
    int                                *flag
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns3__isBusy(
    struct soap *soap,
    // request parameters:
    // response parameters:
    int                                *flag
  );
@endcode

*/

//gsoap ns3  service method-style:	isBusy rpc
//gsoap ns3  service method-encoding:	isBusy http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns3  service method-action:	isBusy ""
int ns3__isBusy(
    int                                *flag	///< Response parameter
);

/******************************************************************************\
 *                                                                            *
 * XML Data Binding                                                           *
 *                                                                            *
\******************************************************************************/


/**

@page page_XMLDataBinding XML Data Binding

SOAP/XML services use data bindings contractually bound by WSDL and auto-
generated by wsdl2h and soapcpp2 (see Service Bindings). Plain data bindings
are adopted from XML schemas as part of the WSDL types section or when running
wsdl2h on a set of schemas to produce non-SOAP-based XML data bindings.

The following readers and writers are C/C++ data type (de)serializers auto-
generated by wsdl2h and soapcpp2. Run soapcpp2 on this file to generate the
(de)serialization code, which is stored in soapC.c[pp]. Include "soapH.h" in
your code to import these data type and function declarations. Only use the
soapcpp2-generated files in your project build. Do not include the wsdl2h-
generated .h file in your code.

XML content can be retrieved from:
  - a file descriptor, using soap->recvfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->is = ...
  - a buffer, using the soap->frecv() callback

XML content can be stored to:
  - a file descriptor, using soap->sendfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->os = ...
  - a buffer, using the soap->fsend() callback


@section ns1 Top-level root elements of schema "urn:Client_1"

@section ns2 Top-level root elements of schema "urn:Client_2"

@section ns3 Top-level root elements of schema "urn:Client_3"

*/

/* End of addclient.h */