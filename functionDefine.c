#include "soapStub.h"
#include "stdsoap2.h"
#include "soapClient.c"
#ifndef soap_call_ns1__ReceiveTaskList
#define soap_call_ns1__ReceiveTaskList(a,b,c,d,e) (0)
SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns1__ReceiveTaskList(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__data *data, struct ns1__ReceiveTaskListResponse *_param_1)
{
	return 0;
}
#endif

#ifndef soap_call_ns2__ReceiveTaskList
extern SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__ReceiveTaskList(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns2__data *data, struct ns2__ReceiveTaskListResponse *_param_3);
#endif

#ifndef soap_call_ns3__ReceiveTaskList
extern SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns3__ReceiveTaskList(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns3__data *data, struct ns3__ReceiveTaskListResponse *_param_1);
#endif

#ifndef soap_call_ns4__ReceiveTaskList
extern SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns4__ReceiveTaskList(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns4__data *data, struct ns4__ReceiveTaskListResponse *_param_1)
{
	return 0;
}
#endif

#ifndef soap_call_ns5__ReceiveTaskList
extern SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns5__ReceiveTaskList(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns5__data *data, struct ns5__ReceiveTaskListResponse *_param_1);
#endif
