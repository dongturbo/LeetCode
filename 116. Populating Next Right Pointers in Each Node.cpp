//递归实现
void connect(TreeLinkNode *root) {
  if (root == nullptr) return;
  TreeLinkNode dummy(-1);
  for (TreeLinkNode *curr = root, *prev = &dummy;
      curr; curr = curr->next) {
      if (curr->left != nullptr){
          prev->next = curr->left;
          prev = prev->next;
      }
      if (curr->right != nullptr){
          prev->next = curr->right;
          prev = prev->next;
      }
  }
  connect(dummy.next);
}
//迭代实现
void connect(TreeLinkNode *root) {
  while (root) {
      TreeLinkNode * next = nullptr; // the first node of next level
      TreeLinkNode * prev = nullptr; // previous node on the same level
      for (; root; root = root->next) {
          if (!next) 
              next = root->left ? root->left : root->right;
          if (root->left) {
              if (prev) prev->next = root->left;
                  prev = root->left;
          }
          if (root->right) {
              if (prev) prev->next = root->right;
                  prev = root->right;
          }
      }
      root = next; // turn to next level
  }
}
