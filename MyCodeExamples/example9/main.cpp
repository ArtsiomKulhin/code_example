std::string* split_string(std::string s1, std::string s2, size_t& k) {
    if (s1.empty()) {
        throw "Передана пустая строка";
    }
    if (s2.empty()) {
        throw "Пустой разделитель";
    }
    size_t kol = 0;
    size_t pos = 0;
    while ((pos = s1.find(s2, pos)) != std::string::npos) {
        ++kol;
        pos += s2.size();
    }
    if (kol == 0) {
        throw "Разделитель не найден в строке";
    }
    k = kol + 1;
    std::string* s = new std::string[k];

    size_t st = 0, idx = 0;
    while ((pos = s1.find(s2, st)) != std::string::npos) {
        s[idx++] = s1.substr(st, pos - st);
        st = pos + s2.size();
    }
    s[idx] = s1.substr(st);

    return s;
}
