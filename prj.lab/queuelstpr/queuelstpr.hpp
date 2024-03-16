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

    void Push(const Complex&) noexcept override;
};

#endif //QUEUELSTPRHPP16032024