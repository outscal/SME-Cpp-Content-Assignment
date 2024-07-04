#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "LinkedListLib/DoubleLinked/DoubleNode.h"
#include "Level/LevelView.h"
#include "Global/Config.h"
#include <iostream>

namespace LinkedListLib
{
    namespace DoubleLinked
    {
        Node* DoubleLinkedList::createNode()
        {
            return new DoubleNode();
        }

        DoubleLinkedList::DoubleLinkedList() = default;

        DoubleLinkedList::~DoubleLinkedList() = default;

        void DoubleLinkedList::insertNodeAtTail()
        {
            linked_list_size++;
            Node* new_node = createNode();
            Node* cur_node = head_node;

            if (cur_node == nullptr)
            {
                head_node = new_node;
                static_cast<DoubleNode*>(new_node)->previous = nullptr;
                initializeNode(new_node, nullptr, Operation::TAIL);
                return;
            }

            while (cur_node->next != nullptr)
            {
                cur_node = cur_node->next;
            }

            cur_node->next = new_node;
            static_cast<DoubleNode*>(new_node)->previous = cur_node;
            initializeNode(new_node, cur_node, Operation::TAIL);
        }

        void DoubleLinkedList::insertNodeAtHead()
        {
            linked_list_size++;
            Node* new_node = createNode();

            if (head_node == nullptr)
            {
                head_node = new_node;
                static_cast<DoubleNode*>(new_node)->previous = nullptr;
                initializeNode(new_node, nullptr, Operation::HEAD);
                return;
            }

            initializeNode(new_node, head_node, Operation::HEAD);

            new_node->next = head_node;
            static_cast<DoubleNode*>(head_node)->previous = new_node;

            head_node = new_node;
        }

        void DoubleLinkedList::insertNodeAtMiddle()
        {
            if (head_node == nullptr) {
                insertNodeAtHead();             // If the list is empty, insert at the head.
                return;
            }

            int midIndex = findMiddleNode();    // Use the existing function to find the middle index
            insertNodeAtIndex(midIndex);             // Use the existing function to insert the node at the found index             
        }

        void DoubleLinkedList::insertNodeAtIndex(int index)
        {
            if (index < 0 || index >= linked_list_size) return;

            if (index == 0)
            {
                insertNodeAtHead();
                return;
            }

            Node* new_node = createNode();
            int current_index = 0;
            Node* cur_node = head_node;
            Node* prev_node = nullptr;

            while (cur_node != nullptr && current_index < index)
            {
                prev_node = cur_node;
                cur_node = cur_node->next;
                current_index++;
            }

            prev_node->next = new_node;
            static_cast<DoubleNode*>(new_node)->previous = prev_node;
            new_node->next = cur_node;
            static_cast<DoubleNode*>(cur_node)->previous = new_node;

            initializeNode(new_node, head_node, Operation::TAIL);
            linked_list_size++;
            
            shiftNodesAfterInsertion(new_node, cur_node, prev_node);
        }

        void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
        {
            Node* next_node = cur_node;
            cur_node = new_node;

            while (cur_node != nullptr && next_node != nullptr)
            {
                cur_node->body_part.setPosition(next_node->body_part.getPosition());
                cur_node->body_part.setDirection(next_node->body_part.getDirection());

                prev_node = cur_node;
                cur_node = next_node;
                next_node = next_node->next;
            }

            initializeNode(cur_node, prev_node, Operation::TAIL);
        }

        void DoubleLinkedList::removeNodeAtTail()
        {
            if (head_node == nullptr) return;

            Node* cur_node = head_node;

            if (cur_node->next == nullptr)
            {
                removeNodeAtHead();
                return;
            }

            while (cur_node->next != nullptr)
            {
                cur_node = cur_node->next;
            }

            linked_list_size--;
            Node* previous_node = static_cast<DoubleNode*>(cur_node)->previous;
            previous_node->next = nullptr;
            delete (cur_node);
        }

        void DoubleLinkedList::removeNodeAtHead()
        {
            linked_list_size--;

            Node* cur_node = head_node;
            head_node = head_node->next;

            if (head_node != nullptr)
            {
                static_cast<DoubleNode*>(head_node)->previous = nullptr;
            }

            cur_node->next = nullptr;
            delete (cur_node);
        }

        void DoubleLinkedList::removeNodeAtMiddle()
        {
            if (head_node == nullptr) return; // If the list is empty, there's nothing to remove

            int midIndex = findMiddleNode();  // Use the existing function to find the middle index
            removeNodeAt(midIndex);           // Use the existing function to remove the node at the found index
        }

        void DoubleLinkedList::removeNodeAt(int index)
        {
            if (index < 0 || index >= linked_list_size) return;

            if (index == 0)
            {
                removeNodeAtHead();
            }
            else
            {
                removeNodeAtIndex(index);
            }
        }

        void DoubleLinkedList::removeNodeAtIndex(int index)
        {
            linked_list_size--;

            int current_index = 0;
            Node* cur_node = head_node;
            Node* prev_node = nullptr;

            while (cur_node != nullptr && current_index < index)
            {
                prev_node = cur_node;
                cur_node = cur_node->next;
                current_index++;
            }

            if (prev_node != nullptr)
            {
                prev_node->next = cur_node->next;
            }

            if (cur_node->next != nullptr)
            {
                Node* next_node = cur_node->next;
                static_cast<DoubleNode*>(next_node)->previous = prev_node;
            }

            shiftNodesAfterRemoval(cur_node);
            delete(cur_node);
        }

        void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
        {
            sf::Vector2i previous_node_position = cur_node->body_part.getPosition();
            Direction previous_node_direction = cur_node->body_part.getDirection();
            cur_node = cur_node->next;

            while (cur_node != nullptr)
            {
                sf::Vector2i temp_node_position = cur_node->body_part.getPosition();
                Direction temp_node_direction = cur_node->body_part.getDirection();

                cur_node->body_part.setPosition(previous_node_position);
                cur_node->body_part.setDirection(previous_node_direction);

                cur_node = cur_node->next;
                previous_node_position = temp_node_position;
                previous_node_direction = temp_node_direction;
            }
        }

        void DoubleLinkedList::removeAllNodes()
        {
            if (head_node == nullptr) return;

            while (head_node != nullptr)
            {
                removeNodeAtHead();
            }
        }

        void DoubleLinkedList::removeHalfNodes()
        {
            if (linked_list_size <= 1) return;
            int half_length = linked_list_size / 2;
            int new_tail_index = half_length - 1;

            std::cout << linked_list_size << ", " << new_tail_index;

            Node* prev_node = findNodeAtIndex(new_tail_index);
            Node* cur_node = prev_node->next;

            while (cur_node != nullptr)
            {
                Node* node_to_delete = cur_node;
                cur_node = cur_node->next;

                delete (node_to_delete);
                linked_list_size--;
            }

            prev_node->next = nullptr;
        }

        Direction DoubleLinkedList::reverse()
        {
            Node* cur_node = head_node;
            Node* prev_node = nullptr;
            Node* next_node = nullptr;

            while (cur_node != nullptr)
            {
                next_node = cur_node->next;
                cur_node->next = prev_node;
                static_cast<DoubleNode*>(cur_node)->previous = next_node;

                prev_node = cur_node;
                cur_node = next_node;
            }

            head_node = prev_node;

            reverseNodeDirections();
            return head_node->body_part.getDirection();
        }
    }
}