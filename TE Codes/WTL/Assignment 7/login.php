<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Book Management System</title>
</head>
<body>
    <h1>Book Management System</h1>

    <!-- Add Book Form -->
    <h2>Add Book</h2>
    <form action="process.php" method="post">
        <label for="title">Title:</label><br>
        <input type="text" id="title" name="title"><br>
        <label for="author">Author:</label><br>
        <input type="text" id="author" name="author"><br>
        <label for="price">Price:</label><br>
        <input type="text" id="price" name="price"><br>
        <label for="quantity">Quantity:</label><br>
        <input type="text" id="quantity" name="quantity"><br><br>
        <input type="submit" value="Add Book">
    </form>

    <!-- Display Books -->
    <h2>Books</h2>
    <?php
    include 'process.php'; // Include PHP file with database connection and functions

    // Retrieve all books
    $books = getAllBooks($conn);

    // Display books in a table
    if (!empty($books)) {
        echo '<table border="1">
                <tr>
                    <th>ID</th>
                    <th>Title</th>
                    <th>Author</th>
                    <th>Price</th>
                    <th>Quantity</th>
                    <th>Action</th>
                </tr>';
        foreach ($books as $book) {
            echo '<tr>
                    <td>' . $book['book_id'] . '</td>
                    <td>' . $book['book_title'] . '</td>
                    <td>' . $book['book_author'] . '</td>
                    <td>' . $book['book_price'] . '</td>
                    <td>' . $book['quantity'] . '</td>
                    <td>
                        <a href="update.php?id=' . $book['book_id'] . '">Update</a> | 
                        <a href="delete.php?id=' . $book['book_id'] . '">Delete</a>
                    </td>
                  </tr>';
        }
        echo '</table>';
    } else {
        echo 'No books available.';
    }
    ?>
</body>
</html>
