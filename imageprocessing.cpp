#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
    Mat img, editedImg;
    string filename;
    int choice;

    cout << "=== SIMPLE IMAGE EDITOR ===" << endl;

    cout << "Enter image filename (with extension, e.g., photo.jpg): ";
    cin >> filename;

    img = imread(filename);
    if(img.empty()) {
        cout << "Cannot load image!" << endl;
        return -1;
    }

    editedImg = img.clone();

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Show Image" << endl;
        cout << "2. Grayscale" << endl;
        cout << "3. Blur" << endl;
        cout << "4. Sharpen" << endl;
        cout << "5. Adjust Brightness" << endl;
        cout << "6. Crop" << endl;
        cout << "7. Resize" << endl;
        cout << "8. Save Image" << endl;
        cout << "9. Exit" << endl;
        cout << "Select option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                imshow("Edited Image", editedImg);
                waitKey(0);
                destroyAllWindows();
                break;
            case 2:
                cvtColor(editedImg, editedImg, COLOR_BGR2GRAY);
                cvtColor(editedImg, editedImg, COLOR_GRAY2BGR); // keep 3 channels
                cout << "Converted to grayscale." << endl;
                break;
            case 3:
                GaussianBlur(editedImg, editedImg, Size(7,7), 0);
                cout << "Blurred image." << endl;
                break;
            case 4: {
                Mat kernel = (Mat_<float>(3,3) <<
                               0, -1, 0,
                              -1, 5, -1,
                               0, -1, 0);
                filter2D(editedImg, editedImg, editedImg.depth(), kernel);
                cout << "Sharpened image." << endl;
                break;
            }
            case 5: {
                int value;
                cout << "Enter brightness adjustment value (-100 to 100): ";
                cin >> value;
                editedImg.convertTo(editedImg, -1, 1, value); // alpha=1, beta=value
                cout << "Brightness adjusted." << endl;
                break;
            }
            case 6: {
                int x, y, w, h;
                cout << "Enter x, y, width, height to crop: ";
                cin >> x >> y >> w >> h;
                Rect roi(x, y, w, h);
                if(x>=0 && y>=0 && x+w <= editedImg.cols && y+h <= editedImg.rows) {
                    editedImg = editedImg(roi);
                    cout << "Image cropped." << endl;
                } else {
                    cout << "Invalid crop region!" << endl;
                }
                break;
            }
            case 7: {
                int newW, newH;
                cout << "Enter new width and height: ";
                cin >> newW >> newH;
                resize(editedImg, editedImg, Size(newW, newH));
                cout << "Image resized." << endl;
                break;
            }
            case 8: {
                string outName;
                cout << "Enter filename to save (e.g., output.jpg): ";
                cin >> outName;
                imwrite(outName, editedImg);
                cout << "Image saved as " << outName << endl;
                break;
            }
            case 9:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while(choice != 9);

    return 0;
}
