#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void WriteVLong(unsigned long n, string& filename) {
  streampos begin, end;
  ofstream file{filename, ios::binary | ios::trunc};
  begin = file.tellp();
  unsigned int flag{0};
  char buf[8];
  char size{0};
  char c;
  for (int i = 0; n; i++) {
    c = (n & 0x7F ) | flag;
    n >>= 7;
    buf[i] = c;
    if (!flag) {
      flag = (1 << 7);
    }
    size++;
  }
  while (size) {
    file.put(buf[size - 1]);
    size--;
  }
  end = file.tellp();
  file.close();
  cout << "size is " << (end - begin) << " bytes" << endl;
}

unsigned long ReadVLong(string filename) {
  ifstream file{filename, ios::binary};
  char flag = 1;
  char c;
  unsigned long result{0};
  while (flag) {
    c = file.get();
    flag = c & (1 << 7);
    result |= (c & 0x7F);
    if (flag) {
      result <<= 7;
    }
  }
  file.close();
  return result;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "wrong number of arguments!" << argc << endl;
    return 1;
  }
  unsigned long original{(unsigned long) atoi(argv[1])};
  string filename{"example.bin"};
  cout << "writing to file: " << filename << endl;
  WriteVLong(original, filename);
  unsigned long value{0};
  value  = ReadVLong(filename);
  cout << "value read: " << value << endl;
  return value != original;
}
