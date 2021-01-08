/* The basic apporach of the programm is that we create a array in which at ith index we create
    the linked list for those whose key value pair generate the same array 
    index(from getBucketIndex()) and in array we store the head address of each linked list
*/
#include<iostream>
#include <string>
using namespace std;
template <typename V>
class MapNode
{
public:
    MapNode *next;
    string key;
    V value;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};
template <typename V>
class OurMap
{
public:
    MapNode<V> **buckets;
    int numBuckets;
    int count;
    OurMap()
    {
         count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~OurMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete [] buckets;
        
    }

    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currentcoff = 1;
        for (int i = key.length() -1 ; i>= 0; i--)
        {
            hashcode += key[i] * currentcoff;
            hashcode = hashcode % numBuckets;
            currentcoff = currentcoff *37;
            currentcoff = currentcoff % numBuckets;
        }

        return hashcode % numBuckets;
        
    }

    void insert (string key , V value)
    {
        int BucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[BucketIndex];
        while (head != NULL)
        {
            if (head -> key == key)
            {
                head -> value = value;
                return;
            }
            head = head ->next;
        }
        head = buckets[BucketIndex];    
        MapNode<V> * node = new MapNode<V>(key,value);
        node -> next = head;
        buckets[BucketIndex] = node;
        count++;     
    }
    int size()             // This size() fucntion gives the no. of key value pair store in the map 
    {
        return count;
    }
    
    V Delete(string key)
    {
        int BucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[BucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if(head -> key == key)
            {
                if(prev == NULL)
                {
                    buckets[BucketIndex] = head -> next;
                }
                else{
                        prev -> next = head -> next;
                        
                }
                V value = head -> value;
                head -> next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head -> next;
            
        }
        return 0;
        
    }
    V getValue(string key)
    {
        int BucketIndex = getBucketIndex(key);
        MapNode<V> * head = buckets[BucketIndex];
        while (head != NULL)
        {
            if(head -> key == key)
            {
                return head -> value;
            }
            head = head -> next;
        }
        return 0;
        
    }
};
int main()
{
    OurMap<int> M1;
    M1.insert("abc" ,1); 
    cout<<M1.getBucketIndex("abc")<<endl;
    M1.insert("bcd" ,1); 
    cout<<M1.getBucketIndex("bcd")<<endl;
    cout<<M1.getValue("abc")<<endl;
    cout<<M1.size()<<endl;
    M1.Delete("abc");
    cout<<M1.size();
    
    
}
