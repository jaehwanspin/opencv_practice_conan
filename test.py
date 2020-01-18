import sys
import cv2

if __name__ == "__main__":
    print(sys.argv[1])
    img = cv2.imread(sys.argv[1], cv2.IMREAD_COLOR)
    cv2.namedWindow("katya", cv2.WINDOW_AUTOSIZE)
    cv2.imshow("katya", img)
    cv2.waitKey(0)
    pass