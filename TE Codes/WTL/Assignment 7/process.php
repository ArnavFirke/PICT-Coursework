 <?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "test";

// Create connection
$conn = new mysqli($servername, $username, $password, $database);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Function to add a new book
function addBook($conn, $book_title, $book_author, $book_price, $quantity) {
    $sql = "INSERT INTO books (book_title, book_author, book_price, quantity) VALUES ('$book_title', '$book_author', $book_price, $quantity)";
    if ($conn->query($sql) === TRUE) {
        echo "Book Added successfully";
        return true;
    } else {
        echo "Book adding failed";
        return false;
    }
}

// Function to update a book
function updateBook($conn, $book_id, $book_title, $book_author, $book_price, $quantity) {
    $sql = "UPDATE books SET book_title='$book_title', book_author='$book_author', book_price=$book_price, quantity=$quantity WHERE book_id=$book_id";
    if ($conn->query($sql) === TRUE) {
        return true;
    } else {
        return false;
    }
}

// Function to delete a book
function deleteBook($conn, $book_id) {
    $sql = "DELETE FROM books WHERE book_id=$book_id";
    if ($conn->query($sql) === TRUE) {
        return true;
    } else {
        return false;
    }
}

// Function to retrieve all books
function getAllBooks($conn) {
    $books = array();
    $sql = "SELECT * FROM books";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            $books[] = $row;
        }
    }
    return $books;
}

// Handle Add Book operation
if(isset($_POST['title']) && isset($_POST['author']) && isset($_POST['price']) && isset($_POST['quantity'])) {
    $book_title = $_POST['title'];
    $book_author = $_POST['author'];
    $book_price = $_POST['price'];
    $quantity = $_POST['quantity'];

    addBook($conn, $book_title, $book_author, $book_price, $quantity);
}

// Handle Update Book operation
if(isset($_POST['update'])) {
    $book_id = $_POST['book_id'];
    $book_title = $_POST['title'];
    $book_author = $_POST['author'];
    $book_price = $_POST['price'];
    $quantity = $_POST['quantity'];

    if(updateBook($conn, $book_id, $book_title, $book_author, $book_price, $quantity)) {
        echo "Book updated successfully.";
    } else {
        echo "Failed to update book.";
    }
}

// Handle Delete Book operation
if(isset($_GET['delete'])) {
    $book_id = $_GET['delete'];
    if(deleteBook($conn, $book_id)) {
        echo "Book deleted successfully.";
    } else {
        echo "Failed to delete book.";
    }
}

// Close connection
// $conn->close();

