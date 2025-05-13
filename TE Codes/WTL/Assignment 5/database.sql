-- Create the table
CREATE TABLE books (
    book_id INT PRIMARY KEY,
    book_title VARCHAR(255),
    book_author VARCHAR(255),
    book_price INT,
    quantity INT
);

-- Insert data into the table
INSERT INTO books VALUES
(1, 'The Great Gatsby', 'F. Scott Fitzgerald', 20, 100),
(2, 'To Kill a Mockingbird', 'Harper Lee', 18, 150),
(3, '1984', 'George Orwell', 15, 200),
(4, 'Pride and Prejudice', 'Jane Austen', 22, 120),
(5, 'The Catcher in the Rye', 'J.D. Salinger', 25, 90),
(6, 'The Hobbit', 'J.R.R. Tolkien', 30, 80),
(7, 'Harry Potter and the Sorcerer''s Stone', 'J.K. Rowling', 28, 180),
(8, 'The Lord of the Rings', 'J.R.R. Tolkien', 35, 75);
