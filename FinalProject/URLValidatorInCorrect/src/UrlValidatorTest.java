/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

    
   public void testManualTest()
   {
	   
	 //This will output failed tests for valid URLs flagged as invalid
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String validUrls[] = {
			   "http://www.amazon.com",
			   "http://www.google.com",
			   "https://www.amazon.com",
			   "https://oregonstate.instructure.com/courses/1648345",
			   "file:///Users/tim/Downloads/FinalProject%20(1).pdf",
			   "http://foo.com/blah_blah",
			   "http://foo.com/blah_blah/",
			   "http://foo.com/blah_blah_(wikipedia)",
			   "http://foo.com/blah_blah_(wikipedia)_(again)",
			   "http://www.example.com/wpstyle/?p=364",
			   "https://www.example.com/foo/?bar=baz&inga=42&quux",
			   "http://✪df.ws/123",
			   "http://userid:password@example.com:8080",
			   "http://userid:password@example.com:8080/",
			   "http://userid@example.com",
			   "http://userid@example.com/",
			   "http://userid@example.com:8080",
			   "http://userid@example.com:8080/",
			   "http://userid:password@example.com",
			   "http://userid:password@example.com/",
			   "http://142.42.1.1/",
			   "http://142.42.1.1:8080/",
			   "http://➡.ws/䨹",
			   "http://⌘.ws",
			   "http://⌘.ws/",
			   "http://foo.com/blah_(wikipedia)#cite-1",
			   "http://foo.com/blah_(wikipedia)_blah#cite-1",
			   "http://foo.com/unicode_(✪)_in_parens",
			   "http://foo.com/(something)?after=parens",
			   "http://☺.damowmow.com/",
			   "http://code.google.com/events/#&product=browser",
			   "http://j.mp",
			   "ftp://foo.bar/baz",
			   "http://foo.bar/?q=Test%20URL-encoded%20stuff",
			   "http://مثال.إختبار",
			   "http://例子.测试",
			   "http://उदाहरण.परीक्षा",
			   "http://-.~_!$&'()*+,;=:%40:80%2f::::::@example.com",
			   "http://a.b-c.de",
			   "http://223.255.255.254"
	   };
	   Boolean expected = true;
	   System.out.println("\nThe following VALID URLs fail the validator:");
	   for (int i = 0; i < validUrls.length; i++) {
		   if (urlVal.isValid(validUrls[i]) != expected) { 
			   System.out.println("\"" + validUrls[i] + "\"");
		   }
	   }	   
		
	   //This will output failed tests for invalid URLs flagged as valid
	   String invalidUrls[] = {
			   "http://-a.b.co",
			   "http://",
			   "http://.",
			   "http://..",
			   "http://../",
			   "http://?",
			   "http://??",
			   "http://??/",
			   "http://#",
			   "http://##",
			   "http://##/",
			   "http://foo.bar?q=Spaces should be encoded",
			   "//",
			   "//a",
			   "///a",
			   "///",
			   "http:///a",
			   "foo.com",
			   "rdar://1234",
			   "h://test",
			   "http:// shouldfail.com",
			   ":// should fail",
			   "http://foo.bar/foo(bar)baz quux",
			   "ftps://foo.bar/",
			   "http://-error-.invalid/",
			   "http://a.b--c.de/",
			   "http://-a.b.co",
			   "http://a.b-.co",
			   "http://0.0.0.0",
			   "http://10.1.1.0",
			   "http://10.1.1.255",
			   "http://224.1.1.1",
			   "http://1.1.1.1.1",
			   "http://123.123.123",
			   "http://3628126748",
			   "http://.www.foo.bar/",
			   "http://www.foo.bar./",
			   "http://.www.foo.bar./",
			   "http://10.1.1.1",
			   "http://10.1.1.254"
	   };
	   expected = false;
	   System.out.println("\nThe following INVALID URLs pass the validator:");
	   for (int i = 0; i < invalidUrls.length; i++) {
		   if (urlVal.isValid(invalidUrls[i]) != expected) { 
			   System.out.println("\"" + invalidUrls[i] + "\"");
		   }
	   }
   }
   
 

// Input Partition Testing
   
   // Test IPv4 Addresses
   // This partition includes invalid IP-like strings as well as valid IP addresses,
   // specifically any address consisting solely of '.' delimited
   // non-negative integers.
   public void testIPv4Address()
   {
	   System.out.println("Starting Partition Test for IPv4-like addresses");
	   UrlValidator urlVal = new UrlValidator();
	   
	   // Test lowest and highest valid IP addresses
	   assertTrue(urlVal.isValid("http://0.0.0.0"));
	   assertTrue(urlVal.isValid("http://255.255.255.255"));
	   
	   // Test just above valid range for each part
	   assertFalse(urlVal.isValid("http://256.256.256.256"));
	   
	   // Test wrong number of number groups
	   assertFalse(urlVal.isValid("http://123.123"));
	   assertFalse(urlVal.isValid("http://123.123.123.123.123"));
	   System.out.println("Finished Partition Test for IPv4-like addresses");
   }
   
   // Test basic host names
   // This partition includes only basic url's with a domain name and TLD,
   // with no queries, paths or fragments
   public void testHostNames()
   {
	   System.out.println("Starting Partition Test for basic host addresses");
	   UrlValidator urlVal = new UrlValidator();

	   // Test a simple, valid example
	   assertTrue(urlVal.isValid("http://test.com"));

	   // Test different TLD's. Using the first and last of the list of valid TLD's 
	   // from here: http://data.iana.org/TLD/tlds-alpha-by-domain.txt (As of Dec. 3 2017)
	   assertTrue(urlVal.isValid("http://test.aaa"));
	   assertTrue(urlVal.isValid("http://test.zw"));
	   
	   // Test multiple dots
	   assertTrue(urlVal.isValid("http://te.st.com"));

	   // Test bad TLD
	   assertFalse(urlVal.isValid("http://test.a1"));

	   // Test bad domain name
	   assertFalse(urlVal.isValid("http://-test.com"));
	   System.out.println("Finished Partition Test for basic host addresses");
   }
   
   // Test valid host names with paths
   // This partition includes no queries or fragments
   public void testPath() 
   {
	   System.out.println("Starting Partition Test for basic host addresses with paths");
	   UrlValidator urlVal = new UrlValidator(); 
	   
	   // Test minimum "/" path
	   assertTrue(urlVal.isValid("http://test.com/"));
	   
	   // Test long path
	   assertTrue(urlVal.isValid("http://test.com/this/is/a/foirly/long/path/that/just/goes/on/and/on/and/on/and/on"));
	   
	   // Test invalid path (< and > aren't allowed)
	   assertFalse(urlVal.isValid("http://test.com/<>"));
	   System.out.println("Finished Partition Test for basic host addresses with paths");

   }
   
   // Test url's with queries
   // This partition includes all URL's with queries, but no fragments  
   public void testQuery()
   {
	   System.out.println("Starting Partition Test for basic host addresses with queries");
	   UrlValidator urlVal = new UrlValidator(); 
	   
	   // Test minimum "?" query
	   assertTrue(urlVal.isValid("http://test.com?"));
	   
	   // Test a fairly long query
	   assertTrue(urlVal.isValid("http://test.com?thisisafoirlylongquerythat/just:goes&on;andon")); 
	   
	   //Test a query with a path
	   assertTrue(urlVal.isValid("http://test.com/?"));

	   
   }
   
   // Test url's with queries
   // This partition includes all URL's with Fragments  
   public void testFragment()
   {
	   System.out.println("Starting Partition Test for basic host addresses with Fragments");
	   UrlValidator urlVal = new UrlValidator(); 
	   
	   // Test minimum "#" fragment
	   assertTrue(urlVal.isValid("http://test.com#"));
	   
	   // Test a fairly long fragment
	   assertTrue(urlVal.isValid("http://test.com#thisisafoirlylongfragmentthat/just:goes&on;andon"));
	   
	   //Test a fragment with a path
	   assertTrue(urlVal.isValid("http://test.com/#"));
	   
	   //Test a fragment with a query
	   assertTrue(urlVal.isValid("http://test.com?#"));
	   
	   //Test a fragment with a path and a query
	   assertTrue(urlVal.isValid("http://test.com/?#"));  
	   
	   System.out.println("Ending Partition Test for basic host addresses with Fragments");

   }
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
