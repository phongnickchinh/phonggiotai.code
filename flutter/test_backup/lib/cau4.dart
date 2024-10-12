// ignore_for_file: prefer_const_constructors

import 'package:flutter/material.dart';

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
  final TextEditingController age = TextEditingController();
  final TextEditingController height = TextEditingController();
  final TextEditingController weight = TextEditingController();
  double _bmi = 0;
  String status = 'hãy nhập thông tin';
  Color textColor=Colors.green;

  void _calculateBMI() {
    double heightInMeters = double.parse(height.text) / 100;
    double weightInKg = double.parse(weight.text);
    double bmi= weightInKg / (heightInMeters * heightInMeters);
    setState(() {
      //lấy giá trị bmi 2 chữ số sau dấu phẩy
      _bmi = double.parse(bmi.toStringAsFixed(2));
      if (bmi < 18.5) {
        status = 'thiếu cơm';
        textColor= Colors.orange;
      } else if (bmi < 24.9) {
        status = 'cân đối vạn người mê';
        textColor=Colors.green;
      } else if (bmi < 29.9) {
        status = 'hơi thừa cân';
        textColor=Colors.orange[700]!;
      } else if (bmi < 34.9) {
        status = 'béo quá, cần giảm cân';
        textColor=Colors.red[400]!;
      }
      else {
        status = 'giảm cân nhanh lên, không thì cook thật đấy :((';
        textColor=Colors.red[900]!;
      }

    });
    print('BMI: $_bmi'); //ignore: avoid_print
  }

  void _reset() {
    setState(() {
      age.clear();
      height.clear();
      weight.clear();
      _bmi = 0;
      status = 'hãy nhập thông tin';
      textColor=Colors.green;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // appBar: AppBar(
      //   title: const Text('My List Tile Demo'),
      //   backgroundColor: Colors.green[300],
      // ),
      body: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Image(
              image: NetworkImage('https://cdn.tgdd.vn/Files/2020/08/10/1278602/cach-tinh-chi-so-bmi-cua-co-the-3_800x433.jpg'),
            ),
            TextField(
              controller: age,
              decoration: const InputDecoration(
                //thêm icon
                icon: Icon(Icons.person),
                labelText: 'Tuổi',
              ),
            ),
            TextField(
              controller: height,
              decoration: const InputDecoration(
                icon: Icon(Icons.straighten),
                labelText: 'Chiều cao (cm)',
              ),
            ),
            TextField(
              controller: weight,
              decoration: const InputDecoration(
                icon: Icon(Icons.line_weight),
                labelText: 'Cân nặng (kg)',
              ),
            ),
            //1 hangf gom 2 nút bấm
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                ElevatedButton(
                  onPressed: () {
                    _calculateBMI();
                  },
                  child: const Text('Tính BMI'),
                ),
                ElevatedButton(
                  onPressed: () {
                    _reset();
                  },
                  child: const Text('Xóa'),
                ),
                ],
            ),
            const SizedBox(height: 20),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [  // Đặt các widget con trong danh sách children
                Text('BMI: $_bmi'),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  'Bạn $status',
                  style: TextStyle(color: textColor),
                ),
              ],
            ),


          ],
        ),
      ),
    );
  }
}
