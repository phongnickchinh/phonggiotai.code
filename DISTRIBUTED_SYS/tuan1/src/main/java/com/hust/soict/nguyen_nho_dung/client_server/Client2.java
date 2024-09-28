package com.hust.soict.nguyen_nho_dung.client_server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;
public class Client2 {

    public static void main(String[] args) {
        try (Socket socket = new Socket("127.0.0.1", 9898);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {
            System.out.println(in.readLine());
            Scanner scanner = new Scanner(System.in);
            while (true) {
                String message = scanner.nextLine();
                if (message.isEmpty()) {
                    break;
                }
                out.println(message);
                System.out.println(in.readLine());
            }
            socket.close();
            scanner.close();

        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
