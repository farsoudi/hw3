#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator comp_;



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();
}


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
  : m_(m), comp_(c)
{
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  data_.push_back(item);
  size_t idx = data_.size() - 1;
  while (idx > 0)
  {
    size_t parent = (idx - 1) / m_;
    if (comp_(data_[idx], data_[parent]))
    {
      std::swap(data_[idx], data_[parent]);
      idx = parent;
    }
    else
    {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    throw std::underflow_error("Heap is empty");
  }
  data_[0] = data_.back();
  data_.pop_back();
  size_t idx = 0;
  while (true)
  {
    size_t child = m_ * idx + 1;
    if (child >= data_.size())
    {
      break;
    }
    size_t minChild = child;
    for (size_t i = 1; i < m_; ++i)
    {
      if (child + i < data_.size() && comp_(data_[child + i], data_[minChild]))
      {
        minChild = child + i;
      }
    }
    if (comp_(data_[minChild], data_[idx]))
    {
      std::swap(data_[idx], data_[minChild]);
      idx = minChild;
    }
    else
    {
      break;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
}



#endif

