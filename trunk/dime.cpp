#include "soapH.h"
#include "dime.h"

#define BUFFER_SIZE 1024
////////////////////////////////////////////////////////////////////////////////
//
//	Server methods
//
////////////////////////////////////////////////////////////////////////////////

int ns__ReceiveTaskList(struct soap* soap,struct ns__data data, struct soap_string& ret)
{
	//if ((soap->omode & SOAP_IO) == SOAP_IO_STORE)
		//soap->omode = (soap->omode & ~SOAP_IO) | SOAP_IO_BUFFER;
	char *name=(char*)soap_malloc(soap,BUFFER_SIZE);
	memset(name,0,BUFFER_SIZE);
	
	//如果id没有设置，不能采用流式传输
	if (data.id==NULL)
	{ sprintf(name,"tasklist.txt");
	  fprintf(stderr, "Saving file %s\n", name);
	  printf("id is NULL\n");
	  saveData(data, name);
	  free(name);
	}
	else 
	{
	 printf("id is not NULL\nid : %s\n",data.id);
	}
	ret.str=(char*)soap_malloc(soap,BUFFER_SIZE);
	sprintf(ret.str,"0\nReceiveTaskList finished.\n");
	ret.size=strlen(ret.str);
	return SOAP_OK;
}

////////////////////////////////////////////////////////////////////////////////
//
//	Helper functions
//
////////////////////////////////////////////////////////////////////////////////

static void saveData(struct ns__data& data, const char *name)
{ char *buf = (char*)data.__ptr;
  int len = data.__size;
  FILE *fd = fopen(name, "wb");
  if (!fd)
  { fprintf(stderr, "Cannot save file %s\n", name);
    return;
  }
  while (len)
  { size_t nwritten = fwrite(buf, 1, len, fd);
    if (!nwritten)
    { fprintf(stderr, "Cannot write to %s\n", name);
      return;
    }
    len -= nwritten;
    buf += nwritten;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//	Streaming DIME attachment content handlers
//
////////////////////////////////////////////////////////////////////////////////

void *dime_write_open(struct soap *soap, const char *id, const char *type, const char *options)
{ // we can return NULL without setting soap->error if we don't want to use the streaming callback for this DIME attachment
  struct dime_write_handle *handle = (struct dime_write_handle*)soap_malloc(soap, sizeof(struct dime_write_handle));
  if (!handle)
  { soap->error = SOAP_EOM;
    return NULL;
  }
  char *name = "tasklist.txt";
  fprintf(stderr, "Saving file %s\n", name);
  handle->name = soap_strdup(soap, name);
  free(name);
  handle->fd = fopen(handle->name, "wb");
  if (!handle->fd)
  { soap->error = SOAP_EOF; // could not open file for writing
    soap->errnum = errno; // get reason
    return NULL;
  }
  return (void*)handle;
}

void dime_write_close(struct soap *soap, void *handle)
{ fclose(((struct dime_write_handle*)handle)->fd);
}

int dime_write(struct soap *soap, void *handle, const char *buf, size_t len)
{ while (len)
  { size_t nwritten = fwrite(buf, 1, len, ((struct dime_write_handle*)handle)->fd);
    if (!nwritten)
    { soap->errnum = errno; // get reason
      return SOAP_EOF;
    }
    len -= nwritten;
    buf += nwritten;
  }
  return SOAP_OK;
}



