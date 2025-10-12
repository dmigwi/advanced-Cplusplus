#include <iostream>
#include <string>

class Document {
    std::string m_content {};

    public:
        Document(const std::string& content)
            : m_content{content} {}

        const std::string& getContent() const {
            return m_content;
        }

        std::string& getContent() {
            return m_content;
        }
};

int main() {
    Document doc {"Sample Text"};

    std::cout << "Const: " << static_cast<const Document>(doc).getContent() << '\n';

    doc.getContent() = "Just joking and that is all";
    std::cout << "Non-const: " << doc.getContent() << '\n';

    return 0;
}