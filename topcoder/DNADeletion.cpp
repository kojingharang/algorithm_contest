// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In genetics, a DNA sequence is a sequence of nucleotides (A, C, G or T).  Some DNA sequences translate to proteins, which are non-empty sequences of amino acids.  Let's examine the DNA translation process::

From left to right, split the DNA sequence into consecutive, non-overlapping triples of nucleotides.  Each triple is called a codon.  There may be one or two nucleotides left over at the end - those should be ignored.  For example, the DNA sequence "ACCTGTACG" will produce the codon sequence "ACC", "TGT", "ACG".  The DNA sequence "ACCTGTAC" will produce the codon sequence "ACC", "TGT" ("AC" is left over and ignored).
You are given a codon table that maps codons to their associated amino acids.  From left to right, look up each codon in the sequence generated above and replace it with its associated amino acid.  Every codon in the sequence must have an associated amino acid - otherwise, the DNA sequence does not translate to a protein.  For example, if "ACC" and "ACG" each map to threonin ("thr") and "TGT" maps to cysteine ("cys"), the DNA sequence "ACCTGTACG" will translate to the protein "thr cys thr".

Sometimes, after replication, one or more nucleotides in a DNA sequence go missing.  This situation is called deletion.  After a deletion, a DNA sequence can become any of its subsequences.  For example, "ACTG" may become "ACG" or "CG".

You are given a vector <string> DNASequence containing a DNA sequence.  Concatenate the elements of DNASequence to obtain the DNA sequence.  You are also given a vector <string> codonTable containing the codon table.  Each element is formatted "CODON AMINOACID" (quotes for clarity), where AMINOACID is the name of the amino acid associated with codon CODON.  Compute the number of different possible proteins that the given DNA sequence can translate to after undergoing zero or more deletions.  Since this number can be quite large, return its value modulo 1000000007.  Remember that only nonempty amino acid sequences are considered proteins.


DEFINITION
Class:DNADeletion
Method:differentProteins
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int differentProteins(vector <string> DNASequence, vector <string> codonTable)


CONSTRAINTS
-DNASequence will contain between 1 and 50 elements, inclusive.
-Every element of DNASequence will contain between 1 and 50 characters, inclusive.
-Every element of DNASequence will contain only characters 'A', 'C', 'T', 'G'.
-codonTable will contain between 1 and 50 elements, inclusive.
-Every element of codonTable will contain a codon, followed by a single space, followed by an amino acid.
-Every codon in codonTable will contain exactly 3 characters.
-Every codon in codonTable will contain only characters 'A', 'C', 'T', 'G'.
-Every codon in codonTable will be unique.
-Every amino acid in codonTable will contain between 1 and 20 characters.
-Every amino acid in codonTable will contain only letters ('a'-'z', 'A'-'Z').


EXAMPLES

0)
{"ACTG"}
{"ACT gua", "ACG cys", "ATG leu", "CTG thr"}

Returns: 4

You can get proteins:
"gua" (deletion of 'G' or no deletion),
"cys" (deletion of 'T'),
"leu" (deletion of 'C'),
"thr" (deletion of 'A').
Other deletions do not result in proteins.

1)
{"AAACCC"}
{"AAA thr", "CCC cys"}

Returns: 3

You can get proteins: "thr", "cys" and "thr cys".

2)
{"AAATCCC"}
{"AAA gua","TCC dop","AAT dop","CCC gua"}

Returns: 5

You can get proteins:
"gua",
"dop",
"gua dop" (from sequence "AAATCC"),
"dop gua" (from sequence "AATCCC"),
"gua gua" (from sequence "AAACCC").

3)
{"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"}
{"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"}

Returns: 455985264

Be sure to concatenate the elements of DNASequence.

*/
// END CUT HERE
#line 89 "DNADeletion.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

int pat[] = {
	0,1,2,
	0,1,3,
	0,2,3,
	0,3,4,
	1,2,3,
	1,3,4,
	2,3,4,
	3,4,5,
};

int amino(char a, char b, char c, vector <string>& cod) {
	cout<<"am "<<a<<b<<c<<endl;
	FOR(v, cod) {
		if(a==(*v)[0]&&b==(*v)[1]&&c==(*v)[2]) {
			cout<<a<<b<<c<<" -> "<<*v<<endl;
			return 1;
		}
	}
	return 0;
}

int f(int st, string& DNA, vector <string>& cod) {
	if(st+2>=DNA.size()) return 1;
	cout<<"f "<<st<<endl;
	int ans = 0;
	REP(i, 8) {
		if(st+pat[i*3+2]>=DNA.size()) continue;
		int am = amino(DNA[st+pat[i*3+0]], DNA[st+pat[i*3+1]], DNA[st+pat[i*3+2]], cod);
		if(am) ans += f(st+pat[i*3+2]+1, DNA, cod);
	}
	cout<<"f "<<st<<" ret "<<ans<<endl;
	return ans;
}

class DNADeletion {
	public:
	int differentProteins(vector <string> DNA, vector <string> cod) {
		string s;
		FOR(v, DNA) s+=*v;
		cout<<s<<endl;
		return f(0, s, cod);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ACTG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ACT gua", "ACG cys", "ATG leu", "CTG thr"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAACCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAA thr", "CCC cys"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AAATCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAA gua","TCC dop","AAT dop","CCC gua"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 455985264; verify_case(3, Arg2, differentProteins(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	DNADeletion ___test;

	//___test.run_test(-1);
	___test.test_case_1();

}

// END CUT HERE
