//
// Created by narbo on 10/31/2024.
//

#include "JNImethods.h"
#include "Board.h"

static Board *board;

JNIEXPORT void JNICALL Java_JNImethods_setBoard
  (JNIEnv *env, jobject obj, const jint dimension) {
  board = new Board(dimension);
}

JNIEXPORT void JNICALL Java_JNImethods_makeMove
  (JNIEnv *env, jobject obj, jint row, jint col) {
  board->makeMove(row, col);
}

JNIEXPORT void JNICALL Java_JNImethods_destroyBoard
  (JNIEnv *env, jobject obj) {
  delete board;
  board = nullptr;
}


JNIEXPORT jchar JNICALL Java_JNImethods_getValue
  (JNIEnv *env, jobject obj,const jint row,const jint col) {
  return board->getValue(row, col);
}

JNIEXPORT jboolean JNICALL Java_JNImethods_checkWin
  (JNIEnv *env, jobject obj, const jchar player) {
  return board->checkWin(player);
}

JNIEXPORT jboolean JNICALL Java_JNImethods_checkDraw
  (JNIEnv *, jobject) {
  return board->checkDraw();
}

JNIEXPORT void JNICALL Java_JNImethods_capture
  (JNIEnv *env, jobject obj, jint row, jint col) {
  board->capture(row, col);
}