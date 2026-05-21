
int count(List* l) {
    if (l == NULL) {
        return 0;
    }
    
    int n = 0;
    Node* current = l->head;
    while (current != NULL) {
        n++;
        current = current->next;
    }
    return n;
}


bool insert_head(List* l, double value) {
    if (l == NULL) {
        return false;
    }
    
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return false;
    }
    
    new_node->value = value;
    new_node->next = l->head;
    
    l->head = new_node;
    
    // Si la liste était vide, mettre à jour tail aussi
    if (l->tail == NULL) {
        l->tail = new_node;
    }
    
    return true;
}


bool pop(List* l, double* out) {
    if (l == NULL || out == NULL || l->tail == NULL) {
        return false;
    }
    
    *out = l->tail->value;
    
    // Cas d'un seul élément
    if (l->head == l->tail) {
        free(l->tail);
        l->head = NULL;
        l->tail = NULL;
        return true;
    }
    
    // Parcourir jusqu'à l'avant-dernier nœud
    Node* current = l->head;
    while (current->next != l->tail) {
        current = current->next;
    }
    
    free(l->tail);
    l->tail = current;
    l->tail->next = NULL;
    
    return true;
}
