#ifndef QUEUELSTPRHPP16032024
#define QUEUELSTPRHPP16032024

#include <complex/complex.hpp>
#include <queuelst/queuelst.hpp>

class QueueLstPr : public QueueLst {
public:
    QueueLstPr() 
        : QueueLst()
    {
    }
    QueueLstPr(const QueueLstPr& rhs) 
        : QueueLst(rhs)
    {
    }
    ~QueueLstPr() = default;
    QueueLstPr& operator=(const QueueLstPr& rhs) {
        if (this != &rhs) {
            while (first_ != nullptr) {
                Node* temp = first_;
                first_ = temp->next_;
                delete temp;
            }
            last_ = nullptr;
            Node* rhs_first = rhs.first_;
            while (rhs_first != nullptr) {
                this->Push(rhs_first->data_);
                rhs_first = rhs_first->next_;
            }
        }
        return *this;
    }

    void Push(const Complex&) noexcept override;
};

#endif //QUEUELSTPRHPP16032024