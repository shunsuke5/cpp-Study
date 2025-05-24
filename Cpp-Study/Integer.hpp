#ifndef INTEGER_H_
#define INTEGER_H_

class Integer {
public:
    // 静的メンバ変数はデフォルト引数に指定可能
    Integer(int num = m_value);
    void Show();

protected:
    static int m_value;
};

#endif // INTEGER_H_