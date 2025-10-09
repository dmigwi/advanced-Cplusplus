#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>

template <typename ArrType>
class MyArray {
 private:
  ArrType *m_data;
  unsigned int m_size;

 public:
  class Iterator {
   public:
    // iterator_trait associated types
    typedef Iterator itr_type;
    typedef ArrType value_type;
    typedef ArrType &reference;
    typedef ArrType *pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    Iterator(pointer ptr) : m_itr_ptr(ptr) {}
    itr_type operator++() {
      itr_type old_itr = *this;
      m_itr_ptr++;
      return old_itr;
    }

    itr_type operator++(int /*dummy*/) {
      m_itr_ptr++;
      return *this;
    }

    itr_type operator--() {
      itr_type old_itr = *this;
      m_itr_ptr--;
      return old_itr;
    }

    itr_type operator--(int /*dummy*/) {
      m_itr_ptr--;
      return *this;
    }

    reference operator*() const { return *m_itr_ptr; }

    pointer operator->() const { return m_itr_ptr; }

    bool operator==(const itr_type &rhs) { return m_itr_ptr == rhs.m_itr_ptr; }

    bool operator!=(const itr_type &rhs) { return m_itr_ptr != rhs.m_itr_ptr; }

   private:
    pointer m_itr_ptr;
  };

  MyArray(unsigned int size) : m_size(size) { m_data = new ArrType[m_size]; }

  unsigned int size() const { return m_size; }

  ArrType &operator[](unsigned int idx) {
    if (idx >= m_size) throw std::runtime_error("Index out of range");
    return m_data[idx];
  }

  Iterator begin() { return Iterator(m_data); }

  Iterator end() { return Iterator(m_data + m_size); }
};

int main() {
  MyArray<double> arr(3);
  arr[0] = 2.6;
  arr[1] = 5.2;
  arr[2] = 8.9;

  std::cout << "MyArray Contents: ";
  for (MyArray<double>::Iterator it = arr.begin(); it != arr.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  std::vector<double> vec;
  std::copy(arr.begin(), arr.end(), std::back_inserter(vec));

  std::cout << "Vector Contents after copy: ";
  for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  std::cout << typeid(std::iterator_traits<
                          MyArray<double>::Iterator>::iterator_category())
                   .name()
            << std::endl;
  return 0;
}

/*OUTPUT
MyArray Contents: 2.6 5.2 8.9
Vector Contents after copy: 2.6 5.2 8.9
FSt26bidirectional_iterator_tagvE
*/