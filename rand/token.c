char* getNextToken(char* string) {
  char* token;
  int charn = 0;
  while (*(string + charn) != " ")
  {
    *(token + charn) = *(string + charn);
    charn++;
  }
  return token;
}

int main() {
  char* test = "3.4 1.1 -2.3";
  char* nextToken = getNextToken(test);
  printf("%s", nextToken);
  return 0;
}