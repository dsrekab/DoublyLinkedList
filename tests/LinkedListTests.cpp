#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/LinkedList.h"

using namespace std;

TEST_CASE("getNodeByOrdinalPosition_returnsNode_WhenValid") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(4999,"unitTest Employee49"));
    sut.addNodeAtHead(Employee(4888,"unitTest Employee48"));

    Node* request = sut.getNodeAtOrdinalPosition(0);
    
    CHECK(request->data.toString() == "[4888:unitTest Employee48]");
}

TEST_CASE("addNodeAtHead_addsANodeToTheHeadOfTheList") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(444,"unitTest Employee04"));
    sut.addNodeAtHead(Employee(333,"unitTest Employee03"));
    sut.addNodeAtHead(Employee(222,"unitTest Employee02"));
    
    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [222:unitTest Employee02] <-> [333:unitTest Employee03] <-> [444:unitTest Employee04] -> T\n");
}

TEST_CASE("addAfterNode_addsANodeToTheMiddleOfTheList") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(5444,"unitTest Employee54"));
    sut.addNodeAtHead(Employee(5333,"unitTest Employee53"));
    sut.addNodeAtHead(Employee(5222,"unitTest Employee52"));

    Node* emp53 = sut.getNodeAtOrdinalPosition(1);

    sut.addAfterNode(emp53, Employee(5111, "unitTest Employee51"));
    
    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [5222:unitTest Employee52] <-> [5333:unitTest Employee53] <-> [5111:unitTest Employee51] <-> [5444:unitTest Employee54] -> T\n");
}

TEST_CASE("addAfterNode_addsANodeToTheEndOfTheListAndUpdatesTail") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(5444,"unitTest Employee54"));
    sut.addNodeAtHead(Employee(5333,"unitTest Employee53"));
    sut.addNodeAtHead(Employee(5222,"unitTest Employee52"));

    Node* emp53 = sut.getNodeAtOrdinalPosition(2);

    sut.addAfterNode(emp53, Employee(5111, "unitTest Employee51"));
    
    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [5222:unitTest Employee52] <-> [5333:unitTest Employee53] <-> [5444:unitTest Employee54] <-> [5111:unitTest Employee51] -> T\n");
}

TEST_CASE("deleteNode_deletesFromStartOfListAndResetsHead") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(7444,"unitTest Employee74"));
    sut.addNodeAtHead(Employee(7333,"unitTest Employee73"));
    sut.addNodeAtHead(Employee(7222,"unitTest Employee72"));
    sut.addNodeAtHead(Employee(7111,"unitTest Employee71"));

    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    Node* emp71 = sut.getNodeAtOrdinalPosition(0);

    sut.deleteNode(emp71);

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [7222:unitTest Employee72] <-> [7333:unitTest Employee73] <-> [7444:unitTest Employee74] -> T\n");
}


TEST_CASE("deleteNode_deletesFromMiddleOfList") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(7444,"unitTest Employee74"));
    sut.addNodeAtHead(Employee(7333,"unitTest Employee73"));
    sut.addNodeAtHead(Employee(7222,"unitTest Employee72"));
    sut.addNodeAtHead(Employee(7111,"unitTest Employee71"));

    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    Node* emp72 = sut.getNodeAtOrdinalPosition(1);

    sut.deleteNode(emp72);

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [7111:unitTest Employee71] <-> [7333:unitTest Employee73] <-> [7444:unitTest Employee74] -> T\n");
}

TEST_CASE("deleteNode_deletesFromEndOfListAndResetsTail") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(7444,"unitTest Employee74"));
    sut.addNodeAtHead(Employee(7333,"unitTest Employee73"));
    sut.addNodeAtHead(Employee(7222,"unitTest Employee72"));
    sut.addNodeAtHead(Employee(7111,"unitTest Employee71"));

    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    Node* emp74 = sut.getNodeAtOrdinalPosition(3);

    sut.deleteNode(emp74);

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [7111:unitTest Employee71] <-> [7222:unitTest Employee72] <-> [7333:unitTest Employee73] -> T\n");
}

TEST_CASE("getNodeByOrdinalPosition_throwsException_WhenOrdinalIsOutOfRange") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(5999,"unitTest Employee59"));
    sut.addNodeAtHead(Employee(5888,"unitTest Employee58"));

    REQUIRE_THROWS_AS(sut.getNodeAtOrdinalPosition(5), out_of_range);
}

TEST_CASE("traverseForward_ShowsHeadAndTailOnly_WhenListIsEmpty") 
{
    LinkedList sut;

    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H ->  -> T\n");
}

TEST_CASE("traverseForward_ShowsHead_Nodes_Tail_WhenListHasMultipleNodes") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(1444,"unitTest Employee14"));
    sut.addNodeAtHead(Employee(1333,"unitTest Employee13"));
    sut.addNodeAtHead(Employee(1222,"unitTest Employee12"));
    
    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseForward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "H -> [1222:unitTest Employee12] <-> [1333:unitTest Employee13] <-> [1444:unitTest Employee14] -> T\n");
}

TEST_CASE("traverseBackward_ShowsTailAndHeadOnly_WhenListIsEmpty") 
{
    LinkedList sut;

    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseBackward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "T ->  -> H\n");
}

TEST_CASE("traverseBackward_ShowsTail_Nodes_Head_WhenListHasMultipleNodes") 
{
    LinkedList sut;

    sut.addNodeAtHead(Employee(2888,"unitTest Employee28"));
    sut.addNodeAtHead(Employee(2777,"unitTest Employee27"));
    sut.addNodeAtHead(Employee(2666,"unitTest Employee26"));
    
    stringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    sut.traverseBackward();

    cout.rdbuf(oldCout);

    CHECK(output.str() == "T -> [2888:unitTest Employee28] <-> [2777:unitTest Employee27] <-> [2666:unitTest Employee26] -> H\n");
}