#include <memory>
#include <atomic>

template<typename T>
class LockFreeQueue {
    struct Node {
        std::shared_ptr<T> m_data;
        std::atomic<Node*> m_next;

        Node() : m_next {nullptr} {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

    public:
        LockFreeQueue () {
            Node* dummy = new Node();
            head.store(dummy);
            tail.store(dummy);
        }

        void push(T const& value) {
            Node* node = new Node();
            node->data = std::make_shared<T>(std::move(value));

            while (true) {
                Node* last = tail.load();
                Node* next = last->next.load();

                if (last == tail.load()) {
                    if (next == nullptr) {
                        if (last->next.compare_exchange_weak(next, node)) {
                            tail.compare_exchange_weak(last, node);
                            return;
                        }
                    } else {
                        tail.compare_exchange_weak(last, next);
                    }
                }
            }
        }
};