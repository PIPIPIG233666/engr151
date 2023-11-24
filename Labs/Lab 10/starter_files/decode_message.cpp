#include "decode_message.h"
#include <string>

int main() {

  ifstream fin("encrypted_codes.txt");   //read this file line-by-line
  ofstream fout("decrypted_codes.txt");  //write only the decode line to this

  /***
  DECODE THE MESSAGE HERE ACCORDING TO
  THE GIVEN ALGORITHM
   ***/
  string line;
  while (getline(fin, line)) {
    if (line.substr(0,1) == "$" || line.substr(0,1) == "#") {
      line = line.substr(1);
      remove_duplicates(line);
      shift(line);
      line = replace_space(line);
    } else {
      remove_key(line);
      line = replace_space(line);
      shift(line);
    }
    fout << line << endl;
  }
  fin.close();
  fout.close();

  return 0;
}
