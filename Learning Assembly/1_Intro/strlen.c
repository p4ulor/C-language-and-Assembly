#if 0
int string_len(char *str) {
	int len = 0;
	while (str[len] != 0)
		len++;
	return len;
}
#endif

int string_len(char *str);

int main() {
	int lenght = string_len("abcdef");
}
