// Implementacao de um BST (Binary Search Tree)

fn main() {
    let mut root: SomeTree = None;

    match &root {
        Some(root) => println!("has value {}", root.val),
        None => println!("has no value"),
    }

    insert(&mut root, 2);
    insert(&mut root, 1);
    insert(&mut root, 4);
    insert(&mut root, 3);
    inline_walk(&root);
}

struct TreeNode {
    val: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}
type SomeTree = Option<Box<TreeNode>>;

// Construtor da struct TreeNode
impl TreeNode {
    fn new(value: i32) -> Self {
        TreeNode {
            val: value,
            left: None,
            right: None,
        }
    }
}

// Insere um valor na BST
// Ignora Duplicatas
fn insert(root: &mut SomeTree, val: i32) {
    if let Some(node) = root {
        if val < node.val {
            insert(&mut node.left, val);
        } else if val > node.val {
            insert(&mut node.right, val);
        }
    } else {
        *root = Some(Box::new(TreeNode::new(val)));
    }
}

fn search(root: &SomeTree, val: i32) -> bool {
    let Some(node) = root;
    if node == None {
        return false
    }
    match root {
        None -> false,
        Some(node) if val == node.val -> true,


    }
}

fn inline_walk(root: &Tree) {
    if let Some(node) = root {
        inline_walk(&node.left);
        println!("{}", node.val);
        inline_walk(&node.right);
    }
}
