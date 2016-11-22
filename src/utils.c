#include <stdio.h>
#include <stdlib.h>

/**
 * read_file reads file content into a buffer
 */
char *
read_file(const char *path) {
  long length;
  char *buf = 0;

  FILE *fp = fopen(path, "r");
  if (!fp) {
    printf("Opening file failed: %s\n", path);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  length = ftell(fp);
  // TODO: check error
  fseek(fp, 0, SEEK_SET);
  buf = malloc(length + 1);

  if (!buf) {
    return NULL;
  }

  size_t read = fread(buf, sizeof(char), length, fp);
  fclose(fp);
  buf[read] = '\0';

  return buf;
}
