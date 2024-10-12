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
  String text = 'Press me, pls';
  Color? color = Colors.yellow[100];

  String changeText(String oldText) {
    return oldText == 'List Tile pressed'
        ? 'Press me, pls'
        : 'List Tile pressed';
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('My List Tile Demo'),
        backgroundColor: Colors.green[300],
      ),
      body: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            ListTile(
              tileColor: color,
              leading: const Icon(Icons.add),
              title: const Text('GFG title'),
              subtitle: const Text('This is subtitle'),
              trailing: const Icon(Icons.done),
              onTap: () {
                setState(() {
                  text = changeText(text);
                  color = color==Colors.yellow[100]?Colors.blue:Colors.yellow[100];
                });
              },
            ),
            const SizedBox(height: 20),
            Align(
              alignment: Alignment.center,
              child: Text(
                text,
                style: const TextStyle(fontSize: 36),
                textAlign: TextAlign.center,
              ),
            ),
          ],
        ),
      ),
    );
  }
}
