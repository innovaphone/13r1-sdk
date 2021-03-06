
/*---------------------------------------------------------------------------*/
/* pbx_admin.h                                                               */
/* copyright (c) innovaphone 2017                                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

class IPbxAdminApi : public UJsonApiContext {
public:
	static class IPbxAdminApi* Create(const char* domain, const char* pbx);
	virtual ~IPbxAdminApi() {};

	virtual void SetPbx(const char* domain, const char* pbx) = 0;
	virtual void MonitorAdminObject(class UPbxMonitorAdminObject* monitor) = 0;
	virtual void MonitorConfig(class UPbxMonitorConfig* monitor) = 0;
	virtual void SendGetConfigObjects() = 0;
	virtual void SendGetObject(const char* cn) = 0;
	virtual void SendUpdateObject(class json_io& msg, char* buffer, word base) = 0;
	virtual void SendGetNodes(ulong64 limit, const char* last) = 0;
	virtual void SendGetStun() = 0;
	virtual void SendGetBooleans(ulong64 limit, const char* last) = 0;
};

class UPbxMonitorAdminObject {
public:
	virtual void PbxAdminObjectUpdate(const char* pwd, const char* key) = 0;
};

class UPbxMonitorConfig {
public:
	virtual void PbxConfigUpdate(const char* domain, const char* pbx, const char* dns) = 0;
	virtual void PbxConfigObjects(class json_io& msg, word base, const char* mt, const char* src) = 0;
	virtual void PbxObject(class json_io& msg, word base, const char* mt, const char* src) = 0;
	virtual void PbxUpdateObject(class json_io& msg, word base, const char* mt, const char* src) = 0;
	virtual void PbxNodes(class json_io& msg, word base, const char* mt, const char* src) = 0;
	virtual void PbxStun(class json_io& msg, word base, const char* mt, const char* src) = 0;
	virtual void PbxBooleans(class json_io& msg, word base, const char* mt, const char* src) = 0;
};