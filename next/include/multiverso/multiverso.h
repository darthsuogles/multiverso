#ifndef MULTIVERSO_INCLUDE_MULTIVERSO_H_
#define MULTIVERSO_INCLUDE_MULTIVERSO_H_

#include "multiverso/table_interface.h"

#include <string>


namespace multiverso {

void MV_Init(int* argc = nullptr, 
             char* argv[] = nullptr, 
             int role = 3,
             bool restart = false,
             int store_each_k = 5);

void MV_Barrier(int iter = -1);

void MV_ShutDown(bool finalize_mpi = true);

int  MV_Rank();
int  MV_Size();

int  MV_NumWorkers();
int  MV_NumServers();

int  MV_WorkerId();
int  MV_ServerId();

int  MV_WorkerIdToRank(int worker_id);
int  MV_ServerIdToRank(int server_id);

//new implementation, but template function should be defined in the same file with declaration
/*
 * param table_type the type string of table, such as "matrix","array"
 * param table_args the parameters of table
 * dump_file_path not used now, to be discussed
 */ 
template<typename Key, typename Val=void>
WorkerTable* MV_CreateTable(const std::string& table_type, const std::vector<void*>& table_args, 
  const std::string& dump_file_path = "") {
  return TableFactory::CreateTable<Key, Val>(table_type, table_args, dump_file_path);
}

int MV_LoadTable(const std::string& dump_file_path);

// Show the dashboard information about the monitored excuation time
// used for profile
void MV_Dashboard();

// --- Net API -------------------------------------------------------------- //
// NOTE(feiga): these API is only used for specific situation.
// Init Multiverso Net with the provided endpoint. Multiverso Net will bind 
// the provided endpoint and use this endpoint to listen and recv message
// \param rank the rank of this MV process
// \param endpoint endpoint with format ip:port, e.g., localhost:9999
// \return  0 SUCCESS
// \return -1 FAIL
int  MV_NetBind(int rank, char* endpoint);

// Connect Multiverso Net with other processes in the system. Multiverso Net 
// will connect these endpoints and send msgs
// \param ranks array of rank
// \param endpoints endpoints for each rank
// \param size size of the array
// \return  0 SUCCESS
// \return -1 FAIL
int  MV_NetConnect(int* rank, char* endpoint[], int size);

} // namespace multiverso

#endif // MULTIVERSO_INCLUDE_MULTIVERSO_H_