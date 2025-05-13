<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" version="1.0" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <html>
            <head>
                <style>
                    table {
                        width: 75%; 
                        border-collapse: collapse;
                        margin: 20px auto; 
                        font-family: Arial, sans-serif;
                    }
                    
                    
                    th, td {
                        padding: 12px;
                        border: 1px solid #ddd;
                        text-align: left;
                    }
                    
                    th {
                        background-color: #4CAF50;
                        color: white;
                    }
                </style>
            </head>
            <body>
                <table border="1">
                    <tr>
                        <th>ID</th>
                        <th>Name</th>
                        <th>Position</th>
                        <th>Department</th>
                        <th>Salary</th>
                    </tr>
                    <xsl:apply-templates select="//employee"/>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="employee">
        <tr>
            <td>
                <xsl:value-of select="@id"/>
            </td>
            <td>
                <xsl:value-of select="name"/>
            </td>
            <td>
                <xsl:value-of select="position"/>
            </td>
            <td>
                <xsl:value-of select="department"/>
            </td>
            <td>
                <xsl:value-of select="salary"/>
            </td>
        </tr>
    </xsl:template>

</xsl:stylesheet>
