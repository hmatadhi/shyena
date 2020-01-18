// C++ program to demonstrate functionality of unordered_map 
#include <iostream> 
#include <unordered_map> 
#include <pcap_context.hpp>
#include <pcap_procedure.hpp>
#include <context_db.hpp>

using namespace std; 
  
bool operator==(pcap_context const &lhs, pcap_context const &rhs) 
{ 
    return ((lhs.get_param_a() == rhs.get_param_a())
        &&  (lhs.get_param_b() == rhs.get_param_b()));
}

bool context_db::check(pcap_context key)
{
    if (this->umap.find(key) == this->umap.end()) {
        cout << "(" << key.get_param_a() << "," 
                    << key.get_param_b() << ")" << " not found\n";
        return false; 
    }
    else {
        cout << "(" << key.get_param_a() << "," 
                    << key.get_param_b() << ")" << " found\n";
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

