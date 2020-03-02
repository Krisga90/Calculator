#include "pch.h"
#include "../calculatorDoubleValues/variableDouble.cpp"
#include "../calculatorDoubleValues/primeNumbers.cpp"


class VariableDoubleTest : public::testing::Test{

protected:
	Variable var,var1,var2,var3,var4;

};


TEST(VariableDoubleTest_, CanInitEmptyVariableClass) {
	Variable var_n;
	ASSERT_DOUBLE_EQ(0, var_n.value(), 0.00001);
}

	
TEST(VariableDoubleTest_, CanInitWithValueVariableClass) {
	Variable var_n(1);
	ASSERT_DOUBLE_EQ(1, var_n.value(),0.00001);
}

TEST_F(VariableDoubleTest, CanInitWithoutAssignedValueClassVariableClass) {
	
	Variable var_n(var);
	ASSERT_DOUBLE_EQ(0, var_n.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanInitWithAssignedValueClassVariableClass) {
	
	var.assign(4);
	Variable var_n(var);
	ASSERT_DOUBLE_EQ(4, var_n.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanAssignWithAssignedValueClassVariableClass) {

	var.assign(5);
	Variable var_n;
	var_n = var;
	ASSERT_DOUBLE_EQ(5, var_n.value(), 0.00001);
}


//				*****operators +=,-=,*=,/=*********


//		****Values
TEST_F(VariableDoubleTest, CanAddValueWithAddAsignOperatorClassVariableClass) {
	var.assign(5);
	var += 4.0;
	ASSERT_DOUBLE_EQ(9, var.value(), 0.00001);
}


TEST_F(VariableDoubleTest, CanSubtractValueWithSubtractAsignOperatorClassVariableClass) {
	var.assign(6.0);
	var -= 4.0;
	ASSERT_DOUBLE_EQ(2.0, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanMultiplyValueWithMultiplyAsignOperatorClassVariableClass) {
	var.assign(1.2);
	var *= 1.2;
	ASSERT_DOUBLE_EQ(1.44, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideValueWithDivideAsignOperatorClassVariableClass) {
	var.assign(6);
	var /= 4.0;
	ASSERT_DOUBLE_EQ(1.5, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideBy0ValueWithDivideAsignOperatorClassVariableClass) {
	var.assign(6);
	ASSERT_THROW(var /= 0, std::invalid_argument);
}

//		******Class Variable

TEST_F(VariableDoubleTest, CanAddClassVariableCWithAddAsignOperatorClassVariableClass) {
	var.assign(5);
	var += Variable(3);
	ASSERT_DOUBLE_EQ(8, var.value(), 0.00001);
}


TEST_F(VariableDoubleTest, CanSubtractClassVariableWithSubtractAsignOperatorClassVariableClass) {
	var.assign(6.0);
	var -= Variable(7.0);
	ASSERT_DOUBLE_EQ(-1.0, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanMultiplyClassVariableWithMultiplyAsignOperatorClassVariableClass) {
	var.assign(1.3);
	var *= Variable(-1.3);
	ASSERT_DOUBLE_EQ(-1.69, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideClassVariableCWithDivideAsignOperatorClassVariableClass) {
	var.assign(1);
	var /= Variable(3);
	ASSERT_DOUBLE_EQ(1.0/3.0, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideBy0ClassVariableCWithDivideAsignOperatorClassVariableClass) {
	var.assign(6);
	ASSERT_THROW(var /= Variable(0), std::invalid_argument);
}


//	END			*****operators +=,-=,*=,/=*********


//				*****operators +,-,*,/*********


TEST_F(VariableDoubleTest, CanAddValueWithAddOperatorClassVariableClass) {
	var.assign(5);
	
	ASSERT_DOUBLE_EQ(9, (var + 4.0).value(), 0.00001);
	ASSERT_DOUBLE_EQ(5, var.value(), 0.00001);
}


TEST_F(VariableDoubleTest, CanSubtractValueWithSubtractOperatorClassVariableClass) {
	var.assign(1.0);
	ASSERT_DOUBLE_EQ(-3.0, (var - 4.0).value(), 0.00001);
	ASSERT_DOUBLE_EQ(1.0, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanMultiplyValueWithMultiplyOperatorClassVariableClass) {
	var.assign(1.2);
	ASSERT_DOUBLE_EQ(-1.44, (var * -1.2).value(), 0.00001);
	ASSERT_DOUBLE_EQ(1.2, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideValueWithDivideOperatorClassVariableClass) {
	var.assign(10);
	ASSERT_DOUBLE_EQ(-2.5, (var / -4.0).value(), 0.00001);
	ASSERT_DOUBLE_EQ(10, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideBy0ValueWithDivideOperatorClassVariableClass) {
	var.assign(6);
	ASSERT_THROW((var/0).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(6, var.value(), 0.00001);
}




//				***** friend operators +,-,*,/*********


TEST_F(VariableDoubleTest, CanAddValueWithFriendAddOperatorClassVariableClass) {
	var.assign(5);

	ASSERT_DOUBLE_EQ(9, (4.0+ var).value(), 0.00001);
	ASSERT_DOUBLE_EQ(5, var.value(), 0.00001);
}


TEST_F(VariableDoubleTest, CanSubtractValueWithFriendSubtractOperatorClassVariableClass) {
	var.assign(1.0);
	
	ASSERT_DOUBLE_EQ(3.0, (4.0 - var).value(), 0.00001);
	ASSERT_DOUBLE_EQ(1.0, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanMultiplyValueWithFriendMultiplyOperatorClassVariableClass) {
	var.assign(1.2);
	ASSERT_DOUBLE_EQ(-1.44, (-1.2* var).value(), 0.00001);
	ASSERT_DOUBLE_EQ(1.2, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideValueWithFriendDivideOperatorClassVariableClass) {
	var.assign(10);
	ASSERT_DOUBLE_EQ(-0.4, (-4.0 / var).value(), 0.00001);
	ASSERT_DOUBLE_EQ(10, var.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideBy0ValueWithFriendDivideOperatorClassVariableClass) {
	var.assign(6);
	ASSERT_THROW((var / 0).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(6, var.value(), 0.00001);
}

//				***** large varied equations

TEST_F(VariableDoubleTest, CanAddMultipleObjectAndValues)
{
	var1.assign(2);
	var2.assign(3);
	var3.assign(5);

	var = 100 + var1 + var2 + 10 + 20 + var3;
	ASSERT_DOUBLE_EQ((100 + 2 + 3 + 10 + 20 + 5), var.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(3, var2.value(), 0.00001);
	ASSERT_DOUBLE_EQ(5, var3.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanSubtractMultipleObjectAndValues)
{
	var1.assign(2);
	var2.assign(3);
	var3.assign(5);

	var = 100 - var1 - var2 + 10 + 20 - var3;
	ASSERT_DOUBLE_EQ((100 - 2 - 3 + 10 + 20 - 5), var.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(3, var2.value(), 0.00001);
	ASSERT_DOUBLE_EQ(5, var3.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanMultiplyMultipleObjectAndValues)
{
	var1.assign(2);
	var2.assign(3);
	var3.assign(5);

	var = 100 * var1 * var2 * 10 + 20 * var3;
	ASSERT_DOUBLE_EQ(((100 * 2 * 3 * 10) + (20 * 5)), var.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(3, var2.value(), 0.00001);
	ASSERT_DOUBLE_EQ(5, var3.value(), 0.00001);
}

TEST_F(VariableDoubleTest, CanDivideMultipleObjectAndValues)
{
	var1.assign(2);
	var2.assign(3);
	var3.assign(5);

	var = 100 / var1 + var2 / 10 + 20 / var3;
	ASSERT_DOUBLE_EQ(((100.0 / 2.0) + (3.0 / 10.0) + (20.0 / 5.0)), var.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(3, var2.value(), 0.00001);
	ASSERT_DOUBLE_EQ(5, var3.value(), 0.00001);
}


TEST_F(VariableDoubleTest, CanDivideMultipleObjectBy0AndValues)
{
	var1.assign(0);
	var2.assign(0);
	var3.assign(0);
	ASSERT_THROW((100 / var1 + var2 / 0 + 20 / var3).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(0, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(0, var2.value(), 0.00001);
	ASSERT_DOUBLE_EQ(0, var3.value(), 0.00001);
}


//		*******test of different Variable like 'a' ,'b' and so on...

TEST_F(VariableDoubleTest, CanAddDifferentVariableClassObject)
{
	var1.assign(1, 'a');
	var2.assign(2, 'b');
	ASSERT_THROW((var1 + var2).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanCubtractDifferentVariableClassObject)
{
	var1.assign(1, 'a');
	var2.assign(2, 'b');
	ASSERT_THROW((var1 + var2).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}


TEST_F(VariableDoubleTest, CanMultiplyDifferentVariableClassObject)
{
	var1.assign(1, 'a');
	var2.assign(2, 'b');
	ASSERT_THROW((var1 * var2).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideDifferentVariableClassObject)
{
	var1.assign(1, 'a');
	var2.assign(2, 'b');
	ASSERT_THROW((var1 / var2).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideBy0DifferentVariableClassObject)
{
	var1.assign(1, 'a');
	var2.assign(0, 'b');
	ASSERT_THROW((var1 / var2).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(0, var2.value(), 0.00001);
}


//   *******test of different index of same Variable like : a^2 , a^3 and so on...

//		same viarable same index

TEST_F(VariableDoubleTest, CanAddSameVariableWithSameIndexVariableClass)
{
	var1.assign(1, 'a');
	var2.assign(2, 'a');
	var3 = var1 + var2;
	ASSERT_DOUBLE_EQ(3, var3.value());
	ASSERT_DOUBLE_EQ(1, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanSubtractSameVariableWithSameIndexVariableClass)
{
	var1.assign(1, 'a');
	var2.assign(2, 'a');
	var3 = var1 - var2;
	ASSERT_DOUBLE_EQ(-1, var3.value());
	ASSERT_DOUBLE_EQ(1, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}


TEST_F(VariableDoubleTest, CanMultiplySameVariableWithSameIndexVariableClass)
{
	var1.assign(1, 'a');
	var2.assign(2, 'a');
	var3 = var1 * var2;
	ASSERT_DOUBLE_EQ(2, var3.value());
	ASSERT_DOUBLE_EQ(2, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideSameVariableWithSameIndexVariableClass)
{
	var1.assign(1, 'a');
	var2.assign(2, 'a');
	var3 = var1 / var2;
	ASSERT_DOUBLE_EQ(0.5, var3.value());
	ASSERT_DOUBLE_EQ(0, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideBy0SameVariableWithSameIndexVariableClass)
{
	var1.assign(1, 'a');
	var2.assign(0, 'a');
	ASSERT_THROW((var1 / var2).value(), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(0, var2.value(), 0.00001);
}

//	END	same viarable same index

//		same viarable same index denominator


TEST_F(VariableDoubleTest, CanAddSameVariableWithSameIndexDenominatorVariableClass)
{
	var1.assign(1, 'a',1);
	var2.assign(2, 'a',2);
	ASSERT_THROW(var1 + var2, std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanSubtractSameVariableWithSameIndexDenominatorVariableClass)
{
	var1.assign(1, 'a', 1);
	var2.assign(2, 'a', 2);
	ASSERT_THROW(var1 - var2, std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}


TEST_F(VariableDoubleTest, CanMultiplySameVariableWithSameIndexDenominatorVariableClass)
{
	var1.assign(1, 'a', 1);
	var2.assign(2, 'a', 2);
	var3 = var1 * var2;
	ASSERT_DOUBLE_EQ(2, var3.value());
	ASSERT_DOUBLE_EQ(3, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideSameVariableWithSameIndexDenominatorVariableClass)
{
	var1.assign(1, 'a', 1);
	var2.assign(2, 'a', 2);
	var3 = var1 / var2;
	ASSERT_DOUBLE_EQ(0.5, var3.value());
	ASSERT_DOUBLE_EQ(-1, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideBy0SameVariableWithSameIndexDenominatorVariableClass)
{
	var1.assign(1, 'a', 1);
	var2.assign(0, 'a', 2);
	ASSERT_THROW((var1 / var2), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(0, var2.value(), 0.00001);
}


//	END	same viarable  same index denominator

//		same viarable different index


TEST_F(VariableDoubleTest, CanAddSameVariableWithDifferentIndexVariableClass)
{
	var1.assign(1, 'a', 1, 2);
	var2.assign(2, 'a', 1, 3);
	ASSERT_THROW(var1 + var2, std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanSubtractSameVariableWithDifferentIndexVariableClass)
{
	var1.assign(1, 'a', 1, 2);
	var2.assign(2, 'a', 1, 3);
	ASSERT_THROW(var1 - var2, std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}


TEST_F(VariableDoubleTest, CanMultiplySameVariableWithDifferentIndexVariableClass)
{
	var1.assign(1, 'a', 1, 2);
	var2.assign(2, 'a', 1, 3);
	var3 = var1 * var2;
	ASSERT_DOUBLE_EQ(2, var3.value());
	ASSERT_DOUBLE_EQ(5.0/6.0, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideSameVariableWithDifferentIndexVariableClass)
{
	var1.assign(1, 'a', 1, 2);
	var2.assign(2, 'a', 1, 3);
	var3 = var1 / var2;
	ASSERT_DOUBLE_EQ(0.5, var3.value());
	ASSERT_DOUBLE_EQ(1.0/6.0, var3.index());
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(2, var2.value(), 0.00001);

}

TEST_F(VariableDoubleTest, CanDivideBy0SameVariableWithDifferentIndexVariableClass)
{
	var1.assign(1, 'a', 1, 2);
	var2.assign(0, 'a', 1, 3);
	ASSERT_THROW((var1 / var2), std::invalid_argument);
	ASSERT_DOUBLE_EQ(1, var1.value(), 0.00001);
	ASSERT_DOUBLE_EQ(0, var2.value(), 0.00001);
}

//testing fractionShortening() function

TEST_F(VariableDoubleTest, FractionShorteningVariableClass)
{
	var1.assign(1, 'a', 2,512 );
	auto indexPair = var1.indexp();
	ASSERT_DOUBLE_EQ(1, indexPair.first, 0.00001);
	ASSERT_DOUBLE_EQ(256, indexPair.second, 0.00001);
}

TEST_F(VariableDoubleTest, DivideFractionShorteningVariableClass)
{
	var1.assign(1, 'a', 5, 6);
	var2.assign(1, 'a', 2, 6);
	auto indexPair = (var1/var2).indexp();
	ASSERT_DOUBLE_EQ(1, indexPair.first, 0.00001);
	ASSERT_DOUBLE_EQ(2, indexPair.second, 0.00001);
}

TEST_F(VariableDoubleTest, MultiplyFractionShorteningVariableClass)
{
	var1.assign(1, 'a', 1, 6);
	var2.assign(1, 'a', 2, 6);
	auto indexPair = (var1 * var2).indexp();
	ASSERT_DOUBLE_EQ(1, indexPair.first, 0.00001);
	ASSERT_DOUBLE_EQ(2, indexPair.second, 0.00001);
}



//	END	same viarable different index

//  END *******test of different index of same Variable like : a^2 , a^3 and so on...











