#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>

using namespace testing;

TEST(ewq, qwe)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}



template<typename EL, int _size>
class ring_buff
{
 private:
    size_t m_size;
    EL m_buf[_size];
    size_t m_front;
    size_t m_back;
    void insert()
    {
        m_back = (m_back + 1) % _size;
        if(_size == size())
           m_front = (m_front + 1) % _size;
        else
           m_size++;
    }

public:
    ring_buff() { clear(); }
    int size() { return m_size; }
    int max_size() { return _size; }

    bool empty() const { return m_size == 0;}
    bool full() const { return m_size == _size;}

    void clear()
    {
        m_size = 0;
        m_front = 0;
        m_back = _size - 1;
    }

    EL& front() { return m_buf[m_front]; }
    EL& back() { return m_buf[m_back];  }

    void push(const EL &elem)
    {
        insert();
        back() = elem;
    }

    void pop()
    {
        if(m_size != 0)
        {
            m_size--;
            m_front = (m_front + 1) % _size;
        }
    }

    void erase_front(const size_t m)
    {
       if(m >= m_size)
           clear();
       else
       {
            m_size -= m;
            m_front = (m_front + m) % _size;
       }
    }

    void erase_back(const size_t m)
    {
        if(m >= m_size)
            clear();
        else
        {
             m_size -= m;
             m_back = (m_front + m_size + 1) % _size;
        }
    }

    void show_buffer()
    {
        if(!empty())
            for(int i = 0; i < m_size; i++)
                std::cout << m_buf[i] << std::endl;

        else
            std::cout << "Buffer is empty..." << std::endl;
    }

};





