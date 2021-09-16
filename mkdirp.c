// mkdirp.c
#include <limits.h>   // PATH_MAX
#include <stdio.h>    // snprintf
#include <stdlib.h>   // realpath
#include <string.h>   // strlen
#include <sys/stat.h> // mkdir

void mkdirp(const char *data_path);

int main(int argc, char *argv[]) {
  char data_path[PATH_MAX];
  realpath(".", data_path);
  snprintf(data_path + strlen(data_path), PATH_MAX - strlen(data_path), "/abc/def/%s/%s", argv[1], argv[2]);
  mkdirp(data_path);

  return 0;
}

void mkdirp(const char *data_path) {
  char path[PATH_MAX];
  for (size_t i = 0; i < strlen(data_path); i++) {
    path[i] = data_path[i];
    if (path[i] == '/') {
      mkdir(path, S_IRWXU);
    }
  }
  mkdir(path, S_IRWXU);
}
