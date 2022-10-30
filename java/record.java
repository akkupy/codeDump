package com.company;

import java.sql.*;
class Main
{
    public static void main(String[] args)
    {
        try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/data?autoReconnect=true&useSSL=false","root","ashu");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from studentdetails");
            System.out.println("No \t Name \t Age \t Place" );
            while(rs.next())
                System.out.println(rs.getInt(1)+"\t"+rs.getString(2)+"\t\t"+rs.getInt(3)+"\t\t"+rs.getString(4));

        }
        catch(Exception e){
            System.out.println(e);}
    }
}
