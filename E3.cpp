#include<iostream>
#include<sstream>
#include<string>

using namespace std;

struct holder{
	string placeholder;
	string key;
	holder * next;
}

holder * Find(holder * head, string placeholer){
	// check every node
	while (head!=NULL){
		if (head->placeholder.compare(placeholder))
			head = head->next; /* not the same */
		else
			return head;
	}
	// not found
	return NULL;
}

void Add(holder* &head, string placeholder, string key){
	// create a new holder
	holder newHoler;
	newHolder.placeholder = placeholder;
	newHolder.key = key;
	newHolder.next = head;
	// Add it to the node list
	head = &newHolder; 
	return;
}

int main(){
	// ask user to input name
	string inputName, tmpName="tmp.txt";
	cout << "Input file: ";
	cin >> inputName;

	// read input file, scan the place holder
	string line;
	ifstream inputFile(inputName);
	if (!inputFile.is_open()){
		cout << "Error! Unable to open " << imputName << endl;
		return -1;
	}
	// at the mean time, init the tmp file
	ofstream tmpFile(tmpName);
	if (!tmpFIle.is_open()){
		cout << "Error! unable to create " << tmpName << endl;
		return -1;
	}
	// start scaning
	while (getline(inputFile,line)){
	    // read a new line
	    size_t pos = 0, found1 = 0, found2 = 0;
	    string placeholder, key;
	    // deal with more than one placeholders
	    while (true){
		// find placeholder
		found1 = line.find('<');
		if (found1==string::npos)
			break; /* no placeholder in this line */
		found2 = line.find('>', find1+1)
		if (found2==string::npos)
			break; /* not a real placehoder*/
		// once get a placeholder, check if it is new
		placeholder = line.substr(found1, found2-found1);
		if (!Find(head,placeholder)){ /* TODO use find function to know if it is new */
			cout << "  " << placeholder.substr(1,found2-found1-2) << ":" ;
			cin >> key;
			cout << endl;
			Add(head, placeholder, key); /* TODO add to node list */
		}
	    }
	}
    	inputFile.close();
	cout << endl;
	// reopen input file. output the reconstructed story
	inputFile.open(inputName);
	if (!inputFile.is_open()){
		cout << "Error! Unable to open " << imputName << endl;
		return -1;
	}
	// start scaning the file again
	while (getline(inputFile,line)){
	    // read a new line again
	    size_t pos = 0, found1 = 0, found2 = 0;
	    string placeholder, key;
	    holder * tmp=NULL;
	    // similarly, deal with more than one placeholders
	    while (true){
		// find placeholder
		found1 = line.find('<');
		if (found1==string::npos)
			break; /* no placeholder in this line */
		found2 = line.find('>', find1+1)
		if (found2==string::npos)
			break; /* not a real placehoder*/
		// once get a placeholder, replace it by the key
		placeholder = line.substr(found1, found2-found1);
		tmp = Find(head,placeholder)
		line.replace(found1, tmp->key);
		}
	    }
	    // print the line
	    cout << line << endl;
	}
	tmpFile.close();
  }

