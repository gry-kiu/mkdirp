// mkdirp.c
#include <limits.h> // PATH_MAX
#include <stdio.h> // snprintf
#include <stdlib.h> // realpath
#include <string.h> // strlen
#include <sys/stat.h> // mkdir

void mkdirp(const char *const path);

int main(int argc, char *argv[]) {
  char path[PATH_MAX];
  realpath(".", path);
  snprintf(path + strlen(path), PATH_MAX - strlen(path), "/abc/def/%s/%s", argv[1], argv[2]);
  mkdirp(path);

  return 0;
}

void mkdirp(const char *const path) {
  char t[PATH_MAX];
  for (size_t i = 0; i < strlen(path); i++) {
    t[i] = path[i];
    if (t[i] == '/') {
      mkdir(t, S_IRWXU);
    }
  }
  mkdir(t, S_IRWXU);
}
