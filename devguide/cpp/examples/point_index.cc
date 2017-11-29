// Copyright 2017 Google Inc. All Rights Reserved.
// Author: ericv@google.com (Eric Veach)
//
// This example shows how to build and query an in-memory index of points
// using S2PointIndex.

#include <cstdio>
#include <gflags/gflags.h>
#include "s2/s2earth.h"
#include "s2/s1chordangle.h"
#include "s2/s2closestpointquery.h"
#include "s2/s2pointindex.h"
#include "s2/s2testing.h"

DEFINE_int32(num_index_points, 10000, "Number of points to index");
DEFINE_int32(num_queries, 10000, "Number of queries");
DEFINE_double(query_radius_km, 100, "Query radius in kilometers");

int main(int argc, char **argv) {
  // Build an index containing random points anywhere on the Earth.
  S2PointIndex<int> index;
  for (int i = 0; i < FLAGS_num_index_points; ++i) {
    index.Add(S2Testing::RandomPoint(), i);
  }

  // Create a query to search within the given radius of a target point.
  S2ClosestPointQuery<int> query(&index);
  query.mutable_options()->set_max_distance(
      S1Angle::Radians(S2Earth::KmToRadians(FLAGS_query_radius_km)));

  // Repeatedly choose a random target point, and count how many index points
  // are within the given radius of that point.
  int64 num_found = 0;
  for (int i = 0; i < FLAGS_num_queries; ++i) {
    S2ClosestPointQuery<int>::PointTarget target(S2Testing::RandomPoint());
    num_found += query.FindClosestPoints(&target).size();
  }

  std::printf("Found %lld points in %d queries\n",
              num_found, FLAGS_num_queries);
  return  0;
}
