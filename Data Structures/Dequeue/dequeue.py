# Contributed by - Sharma Ji <coderbuddyharshit@gmail.com>

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class Deque:
    def __init__(self):
        self.front=None
        self.dequeSize=0
    def isEmpty(self):
        if self.dequeSize==0:
            return True
        return False
    def dequeLength(self):
        return self.dequeSize
    def insertAtFront(self,data):
        temp=Node(data)
        if self.front==None:
            self.front=temp
            self.dequeSize=self.dequeSize+1
        else:
            temp.next=self.front
            self.front=temp
            self.dequeSize=self.dequeSize+1
    def insertAtRear(self,data):
        temp=Node(data)
        if self.front==None:
            self.front=temp
            self.dequeSize=self.dequeSize+1
        else:
            curr=self.front
            while curr.next!=None:
                curr=curr.next
            curr.next=temp
            self.dequeSize=self.dequeSize+1
    def delFromFront(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                temp=self.front
                self.front=self.front.next
                self.dequeSize=self.dequeSize-1
                del temp
        except Exception as e:
            print(str(e))
    def deleteFromRear(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                curr=self.front
                prev=None
                while curr.next!=None:
                    prev=curr
                    curr=curr.next
                prev.next=curr.next
                self.dequeSize=self.dequeSize-1
                del curr
        except Exception as e:
            print(str(e))
    def getfront(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                return self.front.data
        except Exception as e:
            print(str(e))
    def getrear(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                curr=self.front
                while curr.next!=None:
                    curr=curr.next
                return curr.data
        except Exception as e:
            print(str(e))


if __name__ == '__main__':
    de = Deque()
    de.insertAtFront(6)
    de.insertAtRear(9)