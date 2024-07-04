#include "LinkedListLib/LinkedList.h"
#include "Level/LevelView.h"
#include "Global/Config.h"

namespace LinkedListLib
{
    LinkedList::LinkedList()
    {
        head_node = nullptr;
    }

    LinkedList::~LinkedList() = default;

    void LinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
    {
        node_width = width;
        node_height = height;
        default_position = position;
        default_direction = direction;
        linked_list_size = 0;
    }

    void LinkedList::render()
    {
        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            cur_node->body_part.render();
            cur_node = cur_node->next;
        }
    }

    void LinkedList::updateNodeDirection(Direction direction_to_set)
    {
        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            Direction previous_direction = cur_node->body_part.getDirection();
            cur_node->body_part.setDirection(direction_to_set);
            direction_to_set = previous_direction;
            cur_node = cur_node->next;
        }
    }

    void LinkedList::updateNodePosition() 
    {
        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            cur_node->body_part.updatePosition();
            cur_node = cur_node->next;
        }
    }

    void LinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
    {
        if (reference_node == nullptr)
        {
            new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
            return;
        }

        sf::Vector2i position = getNewNodePosition(reference_node, operation);

        new_node->body_part.initialize(node_width, node_height, position, reference_node->body_part.getDirection());
    }

    bool LinkedList::processNodeCollision()
    {
        if (head_node == nullptr) return false;

        sf::Vector2i predicted_position = head_node->body_part.getNextPosition();

        Node* cur_node = head_node->next;
        while (cur_node != nullptr)
        {
            if (cur_node->body_part.getNextPosition() == predicted_position)
            {
                return true;
            }

            cur_node = cur_node->next;
        }

        return false;
    }

    Node* LinkedList::createNode()
    {
        return new Node();
    }

    sf::Vector2i LinkedList::getNewNodePosition(Node* reference_node, Operation operation)
    {
        switch (operation)
        {
        case Operation::HEAD:
            return reference_node->body_part.getNextPosition();
        case Operation::TAIL:
            return reference_node->body_part.getPrevPosition();
        }

        return default_position;
    }

    Node* LinkedList::getHeadNode()
    {
        return head_node;
    }

    int LinkedList::getLinkedListSize()
    {
        return linked_list_size;
    }

    std::vector<sf::Vector2i> LinkedList::getNodesPositionList()
    {
        std::vector<sf::Vector2i> nodes_position_list;

        Node* cur_node = head_node;

        while (cur_node != nullptr)
        {
            nodes_position_list.push_back(cur_node->body_part.getPosition());
            cur_node = cur_node->next;
        }

        return nodes_position_list;
    }

    int LinkedList::findMiddleNode()
    {
        Node* slow = head_node;
        Node* fast = head_node;
        int midIndex = 0;  // This will track the index of the middle node.

        // Move fast pointer at 2x speed and slow pointer at 1x speed.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            midIndex++;
        }

        // Now, slow is at the middle node
        return midIndex;
    }

    Node* LinkedList::findNodeAtIndex(int index)
    {
        int current_index = 0;
        Node* cur_node = head_node;
        Node* prev_node = nullptr;

        while (cur_node != nullptr && current_index <= index)
        {
            prev_node = cur_node;
            cur_node = cur_node->next;
            current_index++;
        }

        return prev_node;
    }

    void LinkedList::reverseNodeDirections()
    {
        Node* curr_node = head_node;

        while (curr_node != nullptr)
        {
            curr_node->body_part.setDirection(getReverseDirection(curr_node->body_part.getPreviousDirection()));
            curr_node = curr_node->next;
        }
    }

    Direction LinkedList::getReverseDirection(Direction reference_direction)
    {
        switch (reference_direction)
        {
        case Direction::UP:
            return Direction::DOWN;
        case Direction::DOWN:
            return Direction::UP;
        case Direction::LEFT:
            return Direction::RIGHT;
        case Direction::RIGHT:
            return Direction::LEFT;
        }
    }
}