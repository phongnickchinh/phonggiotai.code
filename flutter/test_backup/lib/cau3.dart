import 'package:flutter/material.dart';
import 'package:dio/dio.dart';
import 'package:path_provider/path_provider.dart';
import 'dart:io';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'List Tile Demo',
      home: MyStatefulWidget(),
    );
  }
}

class MyStatefulWidget extends StatefulWidget {
  const MyStatefulWidget({super.key});

  @override
  _MyStatefulWidget createState() => _MyStatefulWidget();
}

class _MyStatefulWidget extends State<MyStatefulWidget> {

  Future<bool> downloadImage(String url) async {
    try {
      // Lấy thư mục chứa ảnh DCIM của thiết bị
      Directory? appDocDir = await getExternalStorageDirectory();
      //đặt ảnh ở nơi nào dễ tìm thấy
      String filePath = '${appDocDir!.path}/downloaded.jpg';

      // Tải tệp
      await Dio().download(url, filePath);
      print('Download completed: $filePath'); //ignore: avoid_print
      return true;
    } catch (e) {
      print('Download failed: $e'); //ignore: avoid_print
      return false;
    }
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Câu trả lời câu 3'),
        backgroundColor: Colors.purple[300],
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,  // Căn giữa theo chiều dọc
          crossAxisAlignment: CrossAxisAlignment.center,  // Căn giữa theo chiều ngang
          children: [
            // Nút tải xuống
            ElevatedButton(
              onPressed: () async {
                bool isdowned= await downloadImage('https://cdn2.fptshop.com.vn/unsafe/800x0/meme_che_2_cc087a8d1c.jpg');
                //bật alert
                if(isdowned){
                  showDialog(
                    context: context,
                    builder: (BuildContext context) {
                      return AlertDialog(
                        title: const Text('Download Completed'),
                        content: const Text('File downloaded successfully'),
                        actions: [
                          TextButton(
                            onPressed: () {
                              Navigator.of(context).pop();
                            },
                            child: const Text('OK'),
                          ),
                        ],
                      );
                    },
                  );
                }
              },
              child: const Text('Download File'),
            ),
            const SizedBox(height: 20), // Khoảng cách giữa nút và hình ảnh
            const Image(
              image: NetworkImage('https://cdn2.fptshop.com.vn/unsafe/800x0/meme_che_2_cc087a8d1c.jpg'),
            ),
          ],
        ),
      ),

    );
  }
}
