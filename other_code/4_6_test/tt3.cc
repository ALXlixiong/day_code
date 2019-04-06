   bool Erase(const T& data){
        pBSTNode pParent = _pRoot;
        pBSTNode pCur = _pRoot;
        while(pCur){
            pParent = pCur;
            if(data < pCur->_data){
                pCur = pCur->_pLeft;
            }
            else if(data > pCur->_data){
                pCur = pCur->_pRight;
            }
            else if(data == pCur->_data){
                break;
            }
        }
        if(pCur != nullptr){
            if(pCur->_pRight == nullptr){
                //only have pLeft;
                if(pCur->_pLeft == nullptr){
                    pParent->_pLeft = nullptr;
                    delete pCur;
                    pCur = nullptr;
                }
                else
                    pParent->_pLeft = pCur->_pLeft;
            }
            if(pCur->_pLeft == nullptr){
                //only have pRight;
                if(pCur->_pRight == nullptr){
                    delete pCur;
                    pCur = nullptr;
                }
                else
                    pParent->_pRight = pCur->_pRight;
            }
            if(pCur->_pLeft && pCur->_pRight){
                pBSTNode pLchild = pCur->_pRight;
                pBSTNode pLchildpar = nullptr;
                while(pLchild->_pLeft){
                    pLchildpar = pLchild;
                    pLchild = pLchild->_pLeft;
                }
                pCur->_data = pLchild->_data;
                pLchildpar->_pLeft == nullptr;
                delete pLchild;
                pLchild = nullptr;
            }
        }
        else{
            return false;
        }
        return true;
    }

    pBSTNode GetRoot(){
        return _pRoot;
    }

