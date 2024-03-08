#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;

string query;

vector <string> words;
   
pair<string, string> get_min_max(const string &str) {
    pair<string, string> result;
	string now; now.resize(k);
	for (int id = 0;id < n;id++) {
		string &word = words[id];
		bool match = true;
		for (int i = 0;i < k;i++) {
			if (str[i] == '?') {
				now[i] = word[i];
				continue;
			}
			if (str[i] == '_') {
				now[i] = '_';
				continue;			
			}
			if (str[i] != word[i]) {
				match = false;
				break;
			}			
			now[i] = word[i];
		}
		if (match) {
			if (result.first.empty() || result.first > now) {
				result.first = now;
			}
			if (result.second.empty() || result.second < now) {
				result.second = now;
			}
		}
	}

	return result;
}

string find_next(string);

int main() {

	cin >> n >> k;
	words.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> words[i];
	}	
	cin >> query;	

	cout << find_next(query) << endl;

	return 0;
}