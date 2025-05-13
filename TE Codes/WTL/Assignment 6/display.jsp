<!DOCTYPE html>
<%@ page import="java.sql.*" %>
    <%@ page import="java.io.*" %>
        <html>

        <head>
            <title>Ebooks Details</title>
            <link rel="stylesheet" href="styles.css">
        </head>

        <body>
            <h1>Ebooks Details :-</h1>
            <% try { Class.forName("com.mysql.cj.jdbc.Driver"); Connection con=(Connection)DriverManager.getConnection
                ("jdbc:mysql://localhost:3306/test","root",""); Statement st=con.createStatement(); ResultSet
                rs=st.executeQuery("select * from books;"); %>
                <table border=2px style="text-align:center; ">
                    <thead>
                        <tr>
                            <th>Id</th>
                            <th>Title</th>
                            <th>Author</th>
                            <th>Price</th>
                            <th>quantity</th>
                        </tr>
                    </thead>
                    <tbody>
                        <%while(rs.next()) { %>
                            <tr>
                                <td>
                                    <%=rs.getString("book_id") %>
                                </td>
                                <td>
                                    <%=rs.getString("book_title") %>
                                </td>
                                <td>
                                    <%=rs.getString("book_author") %>
                                </td>
                                <td>
                                    <%=rs.getString("book_price") %>
                                </td>
                                <td>
                                    <%=rs.getString("quantity") %>
                                </td>
                            </tr>
                            <% } %>
                    </tbody>
                </table><br>
                <%} catch(Exception e){ out.print(e.getMessage());%><br>
                    <% } %>
        </body>

        </html>