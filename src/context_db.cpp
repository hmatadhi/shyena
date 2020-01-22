#include <iostream> 
#include <unordered_map> 
#include <pcap_context.hpp>
#include <pcap_procedure.hpp>
#include <context_db.hpp>

using namespace std; 
  
bool context_db::check(pcap_context key)
{
    if (this->umap.find(key) == this->umap.end()) {
        cout << "Tid:" << key.get_tid() << " not found\n";
        return false; 
    }
    else {
        cout << "Tid:" << key.get_tid() << " found\n";
        return true; 
    }
} 

pcap_procedure context_db::get_value(pcap_context key)
{
    return this->umap[key];
}

int context_db::add(pcap_context key, pcap_procedure value)
{
    this->umap[key] = value;
}

