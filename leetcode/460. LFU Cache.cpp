class LFUCache
{
public:
    int numberOfData = 0;
    struct info
    {
        int key, value, counter;
        struct info *prevPtr, *nextPtr;
    } *head = NULL, *tail = NULL;
    map<int, struct info *> getValue, getGroupHead;
    bool garbageData = false;

    LFUCache(int capacity)
    {
        numberOfData = capacity;
        head = NULL;
        tail = NULL;
    }

    void removeAnElementFromMiddle(struct info *item)
    {
        item->prevPtr->nextPtr = item->nextPtr;
        item->nextPtr->prevPtr = item->prevPtr;
    }

    void pushNodeAtTop(struct info *item)
    {
        item->prevPtr = NULL;
        item->nextPtr = head;
        head->prevPtr = item;
        head = item;
    }

    void pushNodeAtBottom(struct info *item)
    {
        tail->nextPtr = item;
        item->prevPtr = tail;
        tail = item;
        tail->nextPtr = NULL;
    }

    void clearAllNodeInfo(struct info *item)
    {
        getValue[item->key] = NULL;
        if(item == getGroupHead[item->counter])
        {
            if(item->nextPtr != NULL && item->counter == item->nextPtr->counter)
            {
                getGroupHead[item->counter] = item->nextPtr;    
            }
            else
            {
                getGroupHead[item->counter] = NULL;
            }
        }
        free(item);
    }

    void pushNodeBeforeTail(struct info *item)
    {
        if(head == tail)
        {
            pushNodeAtTop(item);
        }
        else
        {
            tail->prevPtr->nextPtr = item;
            item->prevPtr = tail->prevPtr;
            item->nextPtr = tail;
            tail->prevPtr = item;
        }
    }

    void pushNodeAtGroupTop(struct info *item)
    {
        struct info *groupHead = getGroupHead[item->counter];

        if(groupHead == head)
        {
            if(head == tail)
            {
                tail->prevPtr = item;
                item->nextPtr = tail;
                item->prevPtr = NULL;
                head = item;
            }
            else
            {
                pushNodeAtTop(item);
            }
        }
        else
        {
            groupHead->prevPtr->nextPtr = item;
            item->prevPtr = groupHead->prevPtr;
            item->nextPtr = groupHead;
            groupHead->prevPtr = item;
        }
    }

    void updatePreviousGroupHead(struct info *item)
    {
        struct info *previousGroupHead = getGroupHead[item->counter];

        if (previousGroupHead != NULL)
        {
            if (previousGroupHead != item)
            {

            }
            else
            {
                if (previousGroupHead->nextPtr != NULL && previousGroupHead->nextPtr->counter == previousGroupHead->counter)
                {
                    getGroupHead[previousGroupHead->counter] = previousGroupHead->nextPtr;
                }
                else
                {
                    getGroupHead[previousGroupHead->counter] = NULL;
                }
            }
        }
    }

    struct info* createNode(int key, int value)
    {
        struct info *ptr = (struct info *)malloc(sizeof(struct info));
        ptr->key = key;
        ptr->value = value;
        ptr->counter = 0;
        ptr->prevPtr = NULL;
        ptr->nextPtr = NULL;
        return ptr;
    }

    void updateList(int key, int value = -1)
    {
        struct info *item = getValue[key];

        if(item == NULL)
        {
            item = createNode(key, value);
            getValue[key] = item;
            item->counter = 1;
            if(numberOfData)
            {
                if(head == NULL && tail == NULL)
                {
                    head = item;
                    tail = item;
                }
                else if(tail->counter > 1)
                {
                    pushNodeAtBottom(item);
                }
                else
                {
                    pushNodeAtGroupTop(item);
                }
            }
            else
            {
                if(head == NULL || tail == NULL)
                {
                    garbageData = true;
                    clearAllNodeInfo(item);
                    return;
                }
                else if(tail->counter > 1)
                {
                    pushNodeBeforeTail(item);
                }
                else
                {
                    pushNodeAtGroupTop(item);
                }
            }
        }
        else
        {
            updatePreviousGroupHead(item);
            item->counter = (item->counter) + 1;
            struct info *groupHead = getGroupHead[item->counter];

            if (groupHead == NULL)
            {
                if (item == head)
                {

                }
                else
                {
                    if (item == tail)
                    {                        
                        tail->prevPtr->nextPtr = NULL;
                        tail = tail->prevPtr;
                    }
                    else
                    {
                        removeAnElementFromMiddle(item);
                    }
                    
                    if (getGroupHead[item->counter-1] == head)
                    {
                        pushNodeAtTop(item);
                    }
                    else if(item->counter < tail->counter)
                    {
                        pushNodeAtBottom(item);
                    }
                    else if(getGroupHead[item->counter-1] == NULL)
                    {
                        // this one occured becaused of frequently updated.....
                        // nothing to do here
                    }
                    else
                    {
                        struct info *aaa = getGroupHead[item->counter-1];
                        aaa->prevPtr->nextPtr = item;
                        item->prevPtr = aaa->prevPtr;
                        item->nextPtr = aaa;
                        aaa->prevPtr = item;
                    }
                }
            }
            else if (groupHead == head)
            {
                if (item->prevPtr == NULL && item->nextPtr != NULL)
                {
                    // this one is itself head, so nothing to do
                }
                else if (item->prevPtr != NULL && item->nextPtr == NULL)
                {
                    // this one is tail
                    struct info *aa = tail->prevPtr;
                    aa->nextPtr = NULL;
                    pushNodeAtTop(tail);
                    tail = aa;
                }
                else
                {
                    removeAnElementFromMiddle(item);
                    pushNodeAtTop(item);
                }
            }
            else
            {
                if (item->prevPtr == NULL && item->nextPtr != NULL)
                {
                    // this one is itself head, so nothing to do
                }
                else if (item->prevPtr != NULL && item->nextPtr == NULL)
                {
                    // this one is tail
                    struct info *aa = tail->prevPtr;
                    aa->nextPtr = NULL;
                    pushNodeAtGroupTop(item);
                    tail = aa;
                }
                else
                {
                    removeAnElementFromMiddle(item);
                    pushNodeAtGroupTop(item);
                }
            }
        }

        getGroupHead[item->counter] = item;
    }

    int get(int key)
    {
        if (getValue[key] == NULL)
        {
            return -1;
        }
        else
        {
            updateList(key);
            return getValue[key]->value;
        }
    }

    void put(int key, int value)
    {
        if (getValue[key] != NULL)
        {
            getValue[key]->value = value;
            updateList(key);
        }
        else
        {
            updateList(key, value);
            
            if(garbageData)
            {
                garbageData = false;
            }
            else if (numberOfData)
            {
                numberOfData--;
            }
            else
            {
                struct info *temp = tail->prevPtr;
                temp->nextPtr = NULL;

                clearAllNodeInfo(tail);
                tail = temp;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ["LFUCache", "put", "put", "put", "get", "get", "get", "put", "put"]
// [[4], [1, 1], [2, 2], [3, 3], [1], [2], [3], [2, 10], [10, 10]]

// ["LFUCache","put","put","get","put","get"]
// [[2],[1,1],[3,3],[3],[4,4],[3]]

// ["LFUCache","put","put","put","get","put","put","get","put","put"]
// [[10],[7,28],[7,1],[8,15],[6],[10,27],[8,10],[8],[6,29],[1,9]]

// ["LFUCache","put","get","put","get","get"]
// [[1],[2,1],[2],[3,2],[2],[3]]

// ["LFUCache","put","put","put", "put"]
// [[2],[1,1],[3,3],[4,4],[5,5]]

// ["LFUCache","put","get"]
// [[0],[0,0],[0]]

// ["LFUCache","put","get","put","put","get","put","put","get","put","put"]
// [[2],[9,12],[9],[4,30],[9,3],[9],[6,14],[3,1],[3],[10,11],[3,27]]