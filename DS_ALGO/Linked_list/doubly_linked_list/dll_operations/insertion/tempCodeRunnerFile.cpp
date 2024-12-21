    newnode->next = std::move(current_ptr->next);
                current_ptr->next = std::move(newnode);
                cu