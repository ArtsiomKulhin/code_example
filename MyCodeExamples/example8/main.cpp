string* transform_and_allocate(string s, string r) {
    if (s.empty()) {
        throw std::invalid_argument("Входная строка не может быть пустой");
    }

    else if (r.size() != 1) {
        throw std::length_error("Заменяющий символ должен быть строкой длины 1");
    }

    else if (!(r[0] >= '0' && r[0] <= '9') && !(r[0] >= 'a' && r[0] <= 'z') && !(r[0] >= 'A' && r[0] <= 'Z')) {
         throw std::invalid_argument("Заменяющий символ должен быть буквой или цифрой");
    }

    else if (s.size() > 1024) {
        throw std::length_error("Максимальная длина строки - 1024 символа");
    }

    char ch = r[0];

    for (int i = 0; i < s.size(); i++) {
        if (isspace(s[i]) || s[i] == '!' || s[i] == '&' || s[i] == '$' || s[i] == '#' || s[i] == '@' || s[i] == ',' || s[i] == '.' ||
            s[i] == '~' || s[i] == '/' || s[i] == '^' || s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '_' || s[i] == '(' || s[i] == ')' || s[i] == '%' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '|' || s[i] == '?' || s[i] == '<' || s[i] == '>' || s[i] == '=' || s[i] == '\\' || s[i] == ';' || s[i] == ':' || s[i] == '\"' || s[i] == '\'') {
            s[i] = ch;
        }
    }

    string* t = new string;

    *t = "";

    for (int i = 0; i < s.size(); i++) {
        *t += s[i];
    }

    return t;
}
